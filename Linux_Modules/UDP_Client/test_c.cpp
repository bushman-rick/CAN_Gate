//this is used to test CAN_UDP_Sevrer by acting as the CAN to Ethernet Gateway



/*
Function:
Generate simulated CAN packet
Transmit CAN packet to CAN_UDP_Server (192.168.0.10:4284)
*/








#include<iostream>
#include<arpa/inet.h> //source: http://unix.superglobalmegacorp.com/xnu/newsrc/bsd/include/arpa/inet.h.html
#include<unistd.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/unistd.h.html
#include<sys/socket.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/socket.h.html
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/netinet/in.h.html
#include<sys/time.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/time.h.html
#include<fstream>
#include<sstream>


using namespace std;

int SERVER_PRT = 4284;
int CLIENT_PRT = 4283;
const char* IP_ADR = "192.168.0.19"; //192.168.0.74 is the actual CAN<>Eth gateway IP


void transmit()
{
	int sockfd;
	//sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in client, server;


	//if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	//{
	//cout << "socket fail" << endl;
	//perror("socket fail");
	//exit(1);
	//}
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	memset(&client, 0, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(IP_ADR);
	client.sin_port = htons(SERVER_PRT);

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(CLIENT_PRT);

	//Assemble CAN packet vv (this is probably not correct...)
	string ts_hi = "22220 ";
	string ts_lo = "11110 ";
	string ide = "1 ";
	string type = "0 ";
	/*
		Type of frame:
			Data Frame	0
			Remote Frame	1
			Bus Error	6
			Transceiver Fault  7
	*/
	string data[] = { "10001 ","10002 ","10003 ","10004 ","10005 ","10006 " };
	string datapack;
	stringstream ss_dp;
	ss_dp << ts_hi << ts_lo << ide << type << data[0] << data[1] << data[2] << data[3] << data[4] << data[5];
	datapack = ss_dp.str();
	char buffer[datapack.size() + 1];

	//cout << datapack << endl;

	int temp = datapack.size();

	for (int a = 0; a <= temp; a++)
	{
		buffer[a] = datapack[a];
	}

	//Assemble CAN packet ^^

	socklen_t s_size = sizeof(server);
	socklen_t c_size = sizeof(client);

	///////////////////////////// v bind socket v
	if (bind(sockfd, (struct sockaddr *) &server, s_size) < 0)
	{
		cout << "bind fail" << endl;
		// write to syslog()
		// kill telem
		return;
	}
	///////////////////////////// ^ bind socket ^

	sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, c_size);

	close(sockfd);
}

int main()
{
	/*
	int y;
	int x = 0;
	cout << "Enter number of packets to send (7 = continuous): ";
	cin >> y;
	if (y == 7)
	{
		cout << "Sending packets.\n";
		do
		{
			cout << "Packet " << x + 1 << " sent..." << endl;
			transmit(x);
			x++;
			//sleep(1); //compiles with g++. installed header but no joy.
		} while (y == 7);
	}
	else
	{
		cout << "Sending " << y << " packets.\n";
		for (x = 0; x < y; x++)
		{
			transmit(x);
			cout << "Packet " << x + 1 << " sent..." << endl;
			//sleep(1); //compiles with g++. installed header but no joy.
		}
	}
	cout << "Done.\n";
	*/
	for (int i = 0; i <= 5; i++)
	{
		transmit();
		sleep(1);
	}
	return 0;
}

