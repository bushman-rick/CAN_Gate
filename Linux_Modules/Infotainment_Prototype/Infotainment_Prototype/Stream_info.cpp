#include<iostream>
#include<unistd.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/unistd.h.html
#include<sys/socket.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/socket.h.html
#include<string.h>
#include<netinet/in.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/netinet/in.h.html

using namespace std;

int SERVER_PRT = 4284; //4284 receive from
string IP_ADR = "192.168.0.10"; //IP of the netbook 

struct sockaddr_in p_client;
int p_CLIENT_PRT = 4281; //transmit to
const char* p_IP_ADR = "192.168.0.10"; //192.168.0.18 is the actual destination ip
int p_sockfd;

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int transmit_init()
{
	p_sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	memset(&p_client, 0, sizeof(p_client));
	p_client.sin_family = AF_INET;
	p_client.sin_addr.s_addr = inet_addr(p_IP_ADR);
	p_client.sin_port = htons(p_CLIENT_PRT);
	return 0;
}

int transmit_send(string packet)
{
	string p_packet = packet;
	int temp = p_packet.size();
	char buffer[temp + 1];

	for (int a = 0; a <= temp; a++) //assembles packet
	{
		buffer[a] = p_packet[a];
	}

	socklen_t c_size = sizeof(p_client);

	if (sendto(p_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &p_client, c_size) < 0) //sends packet
	{
		error("p_send fail");
	}
	else
	{
		cout << "Sent to: " << p_IP_ADR << ":" << p_CLIENT_PRT << endl;
	}
	//close(p_sockfd);
	return 0;
}

void receive()
{
	char _resp = 'y';

	int count = 0;
	cout << "\nReceiving on: " << IP_ADR << " : " << SERVER_PRT << endl;

	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		error("error opening socket");
	}

	int enable = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		error("setsockopt(SO_REUSEADDR) failed");

	struct sockaddr_in server;

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP_ADR.c_str());
	server.sin_port = htons(SERVER_PRT);

	char buffer[20];
	socklen_t s_size = sizeof(server);

	if (bind(sockfd, (struct sockaddr*) &server, s_size) < 0)
	{
		error("bind error");
	}

	if (transmit_init() < 0)
	{
		error("transmit_init error");
	}

	while (_resp == 'y')
	{
		count++;
		if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server, &s_size) < 0)
		{
			error("receive error");
			return;
		}

		cout << "Packet #" << count << "; Data: " << buffer << endl;

		if (transmit_send(buffer) < 0)
		{
			error("transmit_init error");
		}

		for (unsigned int a = 0; a <= sizeof(buffer); a++) //reset buffer
		{
			buffer[a] = '\0';
		}
	}
	close(sockfd);
}
int main()
{
	receive();
}