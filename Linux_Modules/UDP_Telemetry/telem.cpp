// reference http://www.cplusplus.com/forum/unices/76180/
// reference http://stackoverflow.com/questions/9873061/how-to-set-the-source-port-in-the-udp-socket-in-c

/*
Function:
Recieve parsed CAN packet from CAN_UDP_Server vis FIFO
Process packet
Transmit to Android Tablet (192.168.0.18:8353)
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

using namespace std;

int SERVER_PRT; //8353
int CLIENT_PRT; //4283
const char* IP_ADR = "192.168.0.18";

void read_config()
{
	string line;
	ifstream conf("config"); //~/projects/UDP_Telemetry/config
	if (conf.is_open())
	{
		while (getline(conf, line))
		{
			if (line == "SERVER_PRT")
			{
				getline(conf, line);
				SERVER_PRT = atoi(line.c_str()); //convert string to int
			}
			else if (line == "CLIENT_PRT")
			{
				getline(conf, line);
				CLIENT_PRT = atoi(line.c_str()); //convert string to int
			}
			else if (line == "IP_ADR")
			{
				getline(conf, line);
				//IP_ADR = line.c_str(); //convert string to const char* //// I couldnt get this to work ie read the ip from the file 
			}
		}
		cout << "config read:" << endl;
		cout << "Destination port: " << SERVER_PRT << endl;
		cout << "Source port: " << CLIENT_PRT << endl;
		cout << "IP: " << IP_ADR << endl;
		conf.close();
	}
	else cout << "Unable to open file";
	// write to syslog()
	// kill server
	return;
}

void transmit(int x)
{
	/*
	struct in_addr {
	unsigned long s_addr;          // load with inet_pton()
	};

	struct sockaddr_in {
	short            sin_family;   // e.g. AF_INET, AF_INET6
	unsigned short   sin_port;     // e.g. htons(3490)
	struct in_addr   sin_addr;     // see struct in_addr, below
	char             sin_zero[8];  // zero this if you want to
	}client, client;
	*/
	int _x = x;
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

	string datapack = "CANpacket";
	char buffer[16];
	int temp = datapack.size();

	for (int a = 0; a <= temp; a++)
	{
		buffer[a] = datapack[a];
	}

	socklen_t s_size = sizeof(server);
	socklen_t c_size = sizeof(client);

	///////////////////////////// v bind socket v
	if (bind(sockfd, (struct sockaddr *) &client, c_size) < 0)
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
	///////////////////////////// v reads config file v
	// reference: http://www.cplusplus.com/doc/tutorial/files/
	read_config();

	///////////////////////////// ^ reads config file ^

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
}
