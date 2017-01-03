// reference http://www.cplusplus.com/forum/unices/76180/
// reference http://stackoverflow.com/questions/9873061/how-to-set-the-source-port-in-the-udp-socket-in-c

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


using namespace std;
#define DST_PRT 4283
#define SRC_PRT 8353

#define IP_ADR "192.168.0.20"
/*
Got htons definitions from https://linux.die.net/man/3/htons

#include <netinet/in.h>

uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

copied into netinet/in.h
*/


void error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
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
	client.sin_port = htons(DST_PRT);

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(SRC_PRT);
	/*
	Base CAN frame format
	Start-of-frame								1		Denotes the start of frame transmission
	Identifier (green)							11		A (unique) identifier which also represents the message priority
	Remote transmission request (RTR) (blue)	1		Must be dominant (0) for data frames and recessive (1) for remote request frames (see Remote Frame, below)
	Identifier extension bit (IDE)				1		Must be dominant (0) for base frame format with 11-bit identifiers
	Reserved bit (r0)							1		Reserved bit. Must be dominant (0), but accepted as either dominant or recessive.
	Data length code (DLC) (yellow)				4		Number of bytes of data (0–8 bytes)[a]
	Data field (red)							0–64	(0-8 bytes)	Data to be transmitted (length in bytes dictated by DLC field)
	CRC											15		Cyclic redundancy check
	CRC delimiter								1		Must be recessive (1)
	ACK slot									1		Transmitter sends recessive (1) and any receiver can assert a dominant (0)
	ACK delimiter								1		Must be recessive (1)
	End-of-frame (EOF)							7		Must be recessive (1)
	Total (min/max)								44/108 bytes (6/14)
	*/
	string datapack = "CANpacket";
	char buffer[16];
	int temp = datapack.size();

	for (int a = 0; a <= temp; a++)
	{
		buffer[a] = datapack[a];
	}

	socklen_t s_size = sizeof(server);
	socklen_t c_size = sizeof(client);

	bind(sockfd, (struct sockaddr *) &server, s_size);

	sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &client, c_size);

	close(sockfd);
}

int main()
{
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
			sleep(1); //compiles with g++. installed header but no joy.
		} while (y == 7);
	}
	else 
	{
		cout << "Sending " << y << " packets.\n";
		for (x = 0; x < y; x++)
		{
			transmit(x);
			cout << "Packet " << x + 1 << " sent..." << endl;
			sleep(1); //compiles with g++. installed header but no joy.
		}
	}
	cout << "Done.\n";
}
