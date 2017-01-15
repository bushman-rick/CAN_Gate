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
typedef unsigned char byte;
const int INBOUND_BUFFER_SIZE = 28;
const int OUTBOUND_BUFFER_SIZE = 28;
int SERVER_PRT = 4284; //4284 sending port to receive from
int p_CLIENT_PRT = 8353; //destination port to transmit to
const char* SRC_IP_ADR = "192.168.1.67"; //IP of the 'infotainment system' 
const char* DST_IP_ADR = "192.168.1.81"; //destination ip addr to transmit to
struct sockaddr_in client_socket;
struct sockaddr_in server_socket;
int client_socket_id;
int server_socket_id;

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

// server socket initialisation
int server_init()
{
	server_socket_id = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_socket_id < 0)
	{
		error("server_init error opening socket");
	}
	else
	{
		cout << "server_init OK";
	}
	memset(&server_socket, 0, sizeof(server_socket));
	server_socket.sin_family = AF_INET;
	server_socket.sin_addr.s_addr = inet_addr(SRC_IP_ADR);
	server_socket.sin_port = htons(SERVER_PRT);
	return 0;
}

// client socket initialisation
int client_init()
{
	client_socket_id = socket(AF_INET, SOCK_DGRAM, 0);
	if (client_socket_id < 0)
	{
		error("transmit_init error opening socket");
	}
	else
	{
		cout << "client_init OK";
	}
	memset(&client_socket, 0, sizeof(client_socket));
	client_socket.sin_family = AF_INET;
	client_socket.sin_addr.s_addr = inet_addr(DST_IP_ADR);
	client_socket.sin_port = htons(p_CLIENT_PRT);
	return 0;
}

// initialisation 
int process_init()
{
	server_init();
	client_init();
}

//int transmit_send(string packet)
//{
//	string p_packet = packet;
//	int temp = p_packet.size();
//	char buffer[temp + 1];
//
//	for (int a = 0; a <= temp; a++) //assembles packet
//	{
//		buffer[a] = p_packet[a];
//	}
//
//	socklen_t c_size = sizeof(client_socket);
//
//	if (sendto(client_socket_id, buffer, sizeof(buffer), 0, (struct sockaddr *) &client_socket, c_size) < 0) //sends packet
//	{
//		error("p_send fail");
//	}
//	else
//	{
//		cout << "Sent to: " << p_IP_ADR << ":" << p_CLIENT_PRT << endl;
//	}
//	//close(client_socket_id);
//	return 0;
//}

void run()
{
	int count = 0;
	int enable = 1;
	char buffer[INBOUND_BUFFER_SIZE];
	socklen_t s_size = sizeof(server_socket);
	socklen_t c_size = sizeof(client_socket);

	cout << "\nGetting ready to receive on: " << SRC_IP_ADR << " : " << SERVER_PRT << endl;
	
	if (setsockopt(server_socket_id, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
		error("setsockopt(SO_REUSEADDR) failed");
	}

	if (bind(server_socket_id, (struct sockaddr*) &server_socket, s_size) < 0)
	{
		error("bind error");
	}

	while (true)
	{
		count++;
		memset(&buffer, 0, sizeof(buffer));
		if (recvfrom(server_socket_id, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_socket, &s_size) < 0)
		{
			error("receive error");
			return;
		}
		else
		{
			cout << "Packet #" << count << "; Data: " << buffer << endl;
		}

		//*************************************************************************************************************
		// test into processing code, to be moved into it's own function when working
		

		// CORRECT ENDIANNESS
		// inbound is a array of U32 so elements are 4 bytes long.
		const int ELEMENT_SIZE = 4;
		const int ELEMENT_CNT = OUTBOUND_BUFFER_SIZE / ELEMENT_SIZE;
		byte telemetry_data[OUTBOUND_BUFFER_SIZE];

		memset(&telemetry_data, 0, sizeof(telemetry_data));

		for (int m = 0; m < ELEMENT_CNT; ++m)
		{
			for (int n = 0; n < ELEMENT_SIZE; ++n)
			{
				telemetry_data[((m * ELEMENT_SIZE) + (n))] = buffer[((m * ELEMENT_SIZE) + (ELEMENT_SIZE - (n+1)))];
			}
		}

		//*************************************************************************************************************
		
		if (sendto(client_socket_id, telemetry_data, sizeof(telemetry_data), 0, (struct sockaddr *) &client_socket, c_size) < 0) //sends packet
		{
			error("send fail");
		}
		else
		{
			cout << "Sent to: " << DST_IP_ADR << ":" << p_CLIENT_PRT << endl;
			
		}
	}
	close(server_socket_id);
	close(client_socket_id);
}
int main()
{
	process_init();
	run();
}