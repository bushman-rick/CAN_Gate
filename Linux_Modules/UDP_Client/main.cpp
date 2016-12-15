// reference http://www.cplusplus.com/forum/unices/76180/


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


void transmit()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in serv, client;

	/*
	struct in_addr {
	unsigned long s_addr;          // load with inet_pton()
	};

	struct sockaddr_in {
	short            sin_family;   // e.g. AF_INET, AF_INET6
	unsigned short   sin_port;     // e.g. htons(3490)
	struct in_addr   sin_addr;     // see struct in_addr, below
	char             sin_zero[8];  // zero this if you want to
	}serv, client;
	*/

	serv.sin_family = AF_INET;
	serv.sin_port = htons(6666);
	/*
	cout << "Enter IP/n";
	Some code to get an IP
	*/
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
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
	string datapack = "CANpacket\0";
	char buffer[10];

	int temp = datapack.size();
	for (int a = 0; a <= temp; a++)
	{
		buffer[a] = datapack[a];
	}

	__socklen_t l = sizeof(client);
	__socklen_t m = sizeof(serv);
	//socklen_t m = client;
	//cout << "\ngoing to send\n";
	int i = 0;
	while (i <= sizeof buffer)
	{
		//cout << buffer[i];
		i++;
	}
	//cout << "\npls enter the mssg to be sent\n";
	//fgets(buffer, 256, stdin);
	sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serv, m);
	//recvfrom(sockfd, buffer, 256, 0, (struct sockaddr *)&client, &l);
	//
}

int main()
{
	int y;
	cout << "Enter number of packets to send: ";
	cin >> y;
	cout << "Sending " << y << " packets.\n";

	for (int x = 0; x < y; x++)
	{
		printf("%i", x + 1);
		//cout << x + 1;
		//transmit();
		sleep(1); //compiles with g++. installed header but no joy.
	}
	cout << "\nDone.\n";
}
