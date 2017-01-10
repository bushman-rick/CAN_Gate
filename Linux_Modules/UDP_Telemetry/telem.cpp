// reference http://www.cplusplus.com/forum/unices/76180/
// reference http://stackoverflow.com/questions/9873061/how-to-set-the-source-port-in-the-udp-socket-in-c

/*
Function:
Recieve parsed CAN packet from CAN_UDP_Server vis FIFO
	Only when there is something read from FIFO should transmit be executed
Process packet
Transmit to Android Tablet (192.168.0.18:8353)
*/

//###########################################
//compile: "g++ telem.cpp -o UDP_Telemetry"
//###########################################





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
#include<sys/stat.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/stat.h.html
#include<fcntl.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/fcntl.h.html

using namespace std;

int SERVER_PRT; //8353
int CLIENT_PRT; //4283
const char* IP_ADR = "192.168.0.10"; //192.168.0.18 is the actual destination ip

const int FIFO_BUFF = 1024;

void error(const char *msg)
{
	perror(msg);
	//write to syslog
	exit(1);
}

string readFifo()
{
	int fd;
	const char *fifo = "/home/testo/projects/fifo";
	char buff[FIFO_BUFF];

	/* open, read, and display the message from the FIFO */
	fd = open(fifo, O_RDONLY);
	read(fd, buff, FIFO_BUFF);
	cout << "Read from FIFO: " << buff << endl;
	close(fd);

	return "0";
}



void read_config()
{
	string line;
	const char *path = "/home/testo/projects/UDP_Telemetry/config";
	ifstream conf(path);
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
		//cout << "config read:" << endl;
		//cout << "Destination port: " << SERVER_PRT << endl;
		//cout << "Source port: " << CLIENT_PRT << endl;
		//cout << "IP: " << IP_ADR << endl;
		conf.close();
	}
	else
	{
		error("Unable to open file");
		// write to syslog()
		// kill server
	}
	return;
}

void transmit()
{
	///////////////////////////// v read FIFO v
	string fifoBuff = readFifo();
	if (fifoBuff == "-1")
	{
		error("FIFO pipe read fail");
	}

	///////////////////////////// ^ read FIFO ^

	

	///////////////////////////// v process packet v
	//needs work i think
	string datapack = fifoBuff;
	char buffer[128];
	int temp = datapack.size();

	for (int a = 0; a <= temp; a++)
	{
		buffer[a] = datapack[a];
	}
	
	///////////////////////////// ^ process packet ^


	///////////////////////////// v transmit v

	int sockfd;
	//struct sockaddr_in server;
	struct sockaddr_in client;


	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		error("socket fail");
	}

	memset(&client, 0, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(IP_ADR);
	client.sin_port = htons(SERVER_PRT);

	//memset(&server, 0, sizeof(server));
	//server.sin_family = AF_INET;
	//server.sin_addr.s_addr = htonl(INADDR_ANY);
	//server.sin_port = htons(CLIENT_PRT);

	//socklen_t s_size = sizeof(server);
	socklen_t c_size = sizeof(client);


	if (bind(sockfd, (struct sockaddr *) &client, c_size) < 0)
	{
		error("bind fail");
	}
	

	sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, c_size);
	close(sockfd);
	
	///////////////////////////// ^ transmit ^

}

int main()
{
	///////////////////////////// v reads config file v
	// reference: http://www.cplusplus.com/doc/tutorial/files/
	read_config();

	///////////////////////////// ^ reads config file ^

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
			transmit();
			x++;
			//sleep(1); //compiles with g++. installed header but no joy.
		} while (y == 7);
	}
	else
	{
		cout << "Sending " << y << " packets.\n";
		for (x = 0; x < y; x++)
		{
			transmit();
			cout << "Packet " << x + 1 << " sent..." << endl;
			//sleep(1); //compiles with g++. installed header but no joy.
		}
	}
	cout << "Done.\n";
	
	*/
	
	for (int i = 0; i <= 15; i++)
	{
		transmit();
		sleep(1);
	}

	return 0;


}
