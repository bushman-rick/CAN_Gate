//this is used to test UDP_Telemetry by acting as the Android tablet



/*
Function:
Receive UDP packet from UDP_Telemetry (192.168.0.18:8353)
Display the packet or something
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

const int LISTEN_BACKLOG = 100;

int SERVER_PRT = 1234;
int CLIENT_PRT = 8353;
const char* IP_ADR = "192.168.0.18";

void receive(char resp)
{
	char _resp = resp;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server, client;

	memset(&client, 0, sizeof(client));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP_ADR);
	server.sin_port = htons(SERVER_PRT);

	memset(&server, 0, sizeof(server));
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = inet_addr(IP_ADR);
	client.sin_port = htons(CLIENT_PRT);


	char buffer[256];
	socklen_t c_size = sizeof(client);
	socklen_t s_size = sizeof(server);

	///////////////////////////// v bind socket v
	if (bind(sockfd, (struct sockaddr *) &server, s_size) < 0)
	{
		cout << "bind fail" << endl;
		// write to syslog()
		// kill server
		return;
	}
	///////////////////////////// ^ bind socket ^

	int count = 0;

	cout << "\nReceiving from IP: " << IP_ADR << " Port: " << CLIENT_PRT << endl;

	while (_resp == 'y')
	{
		count++;
		///////////////////////////// v Listen v

		if (listen(sockfd, LISTEN_BACKLOG) < 0);
		{
			// write to syslog()
			// kill server
		}

		///////////////////////////// ^ Listen ^

		///////////////////////////// v Accept() v

		int acpt = accept(sockfd, (struct sockaddr *)&client, &c_size);
		if (acpt < 0);
		{
			// write to syslog()
			// kill server
		}

		///////////////////////////// ^ Accept() ^


		///////////////////////////// v receive v

		if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &c_size) < 0)
		{
			cout << "ERROR READING FROM SOCKET";
			// write to syslog()
			// kill server
		}
		cout << "Packet #" << count << "; Data: " << buffer << endl;

		///////////////////////////// ^ receive ^

	}


	close(sockfd);
}
int main()
{
	char resp;
	bool g = true;

	cout << "Receive? (y/n): " << endl;
	cin >> resp;
	if (tolower(resp) == 'n')
	{
		cout << "Exiting..." << endl;
		return 0;
	}
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
