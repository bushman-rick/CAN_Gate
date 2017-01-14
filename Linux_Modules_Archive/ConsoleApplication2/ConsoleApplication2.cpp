// UDP_Test_Client.cpp : Defines the entry point for the console application.
//

/*
Simple udp client
*/
#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <string>
using namespace std;

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "192.168.0.10"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer

//#define PORT 4281   //The port on which to send for outgoing data
#define PORT 8353   //The port on which to send for outgoing data

int main(void)
{

	//char message[28] = { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x0D, 0xF0, 0x8B, 0xD7, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x07, 0x5B, 0xCD, 0x15, 0x00, 0x00, 0x00, 0x00 };

	char message[20] = { 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05 };


	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);

	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//setup address structure
	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	int counter = 0;

	//start communication
	while (1)
	{
		//send the message
		if (sendto(s, message, sizeof(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		counter++;

		printf("Sent: %d \n", counter);

		Sleep(1000);
	}

	closesocket(s);
	WSACleanup();

	return 0;
}