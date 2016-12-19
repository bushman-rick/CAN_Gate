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
#define DST_PRT 8353
#define SRC_PRT 4283

#define IP_ADR "192.168.0.20"

void error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void receive(char resp)
{
	char _resp = resp;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server, client;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP_ADR);
	server.sin_port = htons(DST_PRT);

	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(IP_ADR);
	client.sin_port = htons(SRC_PRT);


	char buffer[256];
	socklen_t c_size = sizeof(client);
	socklen_t s_size = sizeof(server);
	bind(sockfd, (struct sockaddr *) &client, c_size);

	int pack_count = 0;

	cout << "\nReceiving from " << " IP: " << IP_ADR << " Port: " << SRC_PRT << endl;

	while (_resp == 'y')
	{
		pack_count++;
		int rc = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &c_size);
		if (rc < 0)
		{
			cout << "ERROR READING FROM SOCKET";
		}
		cout << "Packet # "<< pack_count <<  " Data: " << buffer << endl;
		//output to file???
		//cin >> _resp;
		//if (_resp == 'n')
		//{
		//	break;
		//}
	}

	close(sockfd);
}
int main()
{
	char resp;
	bool g = true;

	cout << "Receive? (y/n): " << endl;
	cin >> resp;
	receive(resp);
	//while (resp == 'y');
	//cout << pack_count;
	//while (g == true);
	//{
		//cout << pack_count;
		//receive();
		//cin >> resp;
		//pack_count++;
	//} 
}
