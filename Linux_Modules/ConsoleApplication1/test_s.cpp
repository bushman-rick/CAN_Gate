//this is used to test UDP_Telemetry by acting as the Android tablet

/*
Function:
Receive UDP packet from UDP_Telemetry (CAN_UDP_Telemetry for prototype) (192.168.0.18:8353)
Display the packet or something
*/

/*
TODO:
- take socket intialisation out of loop
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
#include<sys/stat.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/stat.h.html
#include<fcntl.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/fcntl.h.html

using namespace std;

int SERVER_PRT = 4281; //4281 receive from
const char* IP_ADR = "192.168.0.10";

void error(const char *msg)
{
	perror(msg);
	//write to syslog
	exit(1);
}

void receive(char resp)
{
	char _resp = resp;
	
	int count = 0;
	cout << "\nReceiving on: " << IP_ADR << " : " << SERVER_PRT << endl;

	while (_resp == 'y')
	{
		///////////////////////////// v bind socket v

		int sockfd;
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if (sockfd < 0)
		{
			cout << "error opening socket" << endl;
		}

		int enable = 1;
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		{
			error("setsockopt(SO_REUSEADDR) failed");
		}

		struct sockaddr_in server, client;

		memset(&server, 0, sizeof(server));
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = inet_addr(IP_ADR);
		server.sin_port = htons(SERVER_PRT);

		char buffer[256];
		socklen_t s_size = sizeof(server);

		if (bind(sockfd, (struct sockaddr*) &server, s_size) < 0)
		{
			error("bind error");
		}
		///////////////////////////// ^ bind socket ^

		count++;

		///////////////////////////// v receive v

		if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server, &s_size) < 0)
		{
			error("ERROR READING FROM SOCKET");
			// write to syslog()
			// kill server
			return;
		}
		cout << "Packet #" << count << "; Data: " << buffer << endl;
		///////////////////////////// ^ receive ^

		close(sockfd);
	}

}
int main()
{
	char resp = 'y';
	bool g = true;

	receive(resp);

}

