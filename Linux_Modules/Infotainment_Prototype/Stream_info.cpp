#include<iostream>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
// Some include files (headers) are not bundeled by default with the Linux extention to Visual Studio.
// The missing headers have been sourced from the location below and added to the developemnt machine at following location
//"D:\Program Files\VS Enterprise 2015\VC\Linux\include\usr\include" or
//"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\Linux\include\usr\include"
#include<arpa/inet.h> //source: http://unix.superglobalmegacorp.com/xnu/newsrc/bsd/include/arpa/inet.h.html
#include<unistd.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/unistd.h.html
#include<sys/socket.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/socket.h.html
#include<netinet/in.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/netinet/in.h.html
#include<sys/time.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/time.h.html
#include<sys/stat.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/stat.h.html
#include<fcntl.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/fcntl.h.html

using namespace std;
typedef unsigned char byte;
const int INBOUND_BUFFER_SIZE = 28;
const int OUTBOUND_BUFFER_SIZE = 28;
const int FOWARD_RATIO = 30;
const int ID_ELEMENT = 3;
const int ELEMENT_SIZE = 4;
const int ELEMENT_CNT = OUTBOUND_BUFFER_SIZE / ELEMENT_SIZE;
int SERVER_PRT = 4284; //4284 sending port to receive from
int p_CLIENT_PRT = 8353; //destination port to transmit to
const char* SRC_IP_ADR = "192.168.1.70"; //IP of the 'infotainment system' 
const char* DST_IP_ADR = "192.168.1.154"; //destination ip addr to transmit to
struct sockaddr_in client_socket;
struct sockaddr_in server_socket;
int client_socket_id;
int server_socket_id;

// boradcast erro to OS and exit
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

// main function, messages are received, processed and published in a permanent loop.
void run()
{
	int count = 0;
	int enable = 1;
	int identifier_1_cnt = 0;
	int identifier_2_cnt = 0;
	char buffer[INBOUND_BUFFER_SIZE];
	socklen_t s_size = sizeof(server_socket);
	socklen_t c_size = sizeof(client_socket);

	// setup server socket to listen for incoming messages.
	// set options
	cout << "\nGetting ready to receive on: " << SRC_IP_ADR << " : " << SERVER_PRT << endl;
	if (setsockopt(server_socket_id, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
		error("setsockopt(SO_REUSEADDR) failed");
	}
	// bind address
	if (bind(server_socket_id, (struct sockaddr*) &server_socket, s_size) < 0)
	{
		error("bind error");
	}

	// main loop, messages are received, processed and re-published
	while (enable)
	{
		// message counter
		count++;
		// buffer for inbound messages
		memset(&buffer, 0, sizeof(buffer));

		// call recieve
		if (recvfrom(server_socket_id, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_socket, &s_size) < 0)
		{
			error("receive error");
			return;
		}
		else
		{
			if (count%FOWARD_RATIO == 0)
			{
				cout << "    Packet #" << count << "; Receive on: " << SRC_IP_ADR << " : " << SERVER_PRT << endl;
			}
		}

		//*************************************************************************************************************
		// this section processes data and correct endeness 
		byte telemetry_data[OUTBOUND_BUFFER_SIZE];
		byte id_element[ELEMENT_SIZE];
		int element_0, element_1, element_2, identifier, element_4, element_5, element_6;
		// telemetry_data = buffer for the inbound data
		memset(&telemetry_data, 0, sizeof(telemetry_data));

		// inbound data is expected in byte array of 7 x 32 UINT's
		// the order of each four bytes are reveresed to correct endeness 
		for (int m = 0; m < ELEMENT_CNT; ++m)
		{
			for (int n = 0; n < ELEMENT_SIZE; ++n)
			{
				telemetry_data[((m * ELEMENT_SIZE) + (n))] = buffer[((m * ELEMENT_SIZE) + (ELEMENT_SIZE - (n+1)))];
				if (m == ID_ELEMENT)
				{
					id_element[n] = telemetry_data[((m * ELEMENT_SIZE) + (n))];
				}
			}
		}

		// each element of the telemetry_data array is copied to a INT object
		memcpy(&element_0, telemetry_data + 0, sizeof(element_0));
		memcpy(&element_1, telemetry_data + 4, sizeof(element_1));
		memcpy(&element_2, telemetry_data + 8, sizeof(element_2));
		memcpy(&identifier, telemetry_data + 12, sizeof(identifier));
		memcpy(&element_4, telemetry_data + 16, sizeof(element_4));
		memcpy(&element_5, telemetry_data + 20, sizeof(element_5));
		memcpy(&element_6, telemetry_data + 28, sizeof(element_6));

		cout << "    Data: "  << element_0 << " : " << element_1 << " : " << element_2 << " : " << identifier << " : " << element_4 << " : " << element_5 << " : " << element_6 << " : " << endl;

		//*************************************************************************************************************

		// every n'th message. accoring to the FOWARD_RATIO is republished for the telemetry target
		if (count%FOWARD_RATIO == 0)
		{
			if (sendto(client_socket_id, telemetry_data, sizeof(telemetry_data), 0, (struct sockaddr *) &client_socket, c_size) < 0) //sends packet
			{
				error("send fail");
			}
			else
			{
				cout << "    Sent to: " << DST_IP_ADR << ":" << p_CLIENT_PRT << " with identifier: " << identifier << endl;
			}
		}

	}
	close(server_socket_id);
	close(client_socket_id);
}
// main loop
int main()
{
	process_init();
	run();
}