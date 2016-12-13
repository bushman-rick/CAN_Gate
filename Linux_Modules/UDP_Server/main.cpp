#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <netinet/in.h> //google for source and dump in D:\Program Files\VS Enterprise 2015\VC\Linux\include\usr\include\x86_64-linux-gnu
#include <sys/socket.h> //google for source and dump in D:\Program Files\VS Enterprise 2015\VC\Linux\include\usr\include\x86_64-linux-gnu
#include <arpa/inet.h> //google for source and dump in D:\Program Files\VS Enterprise 2015\VC\Linux\include\usr\include\x86_64-linux-gnu


int main()
{
    printf("hello from UDP_Server!\n");
	//Just going to try out sending a UDP packet
	//using:
	//https://www.techpowerup.com/forums/threads/c-c-sockets-faq-and-how-to-win-linux.56901/
	//http://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html

	int thisSocket;
	struct sockaddr_in  {
		short            sin_family;   // e.g. AF_INET
		unsigned short   sin_port;     // e.g. htons(3490)
		struct in_addr   sin_addr;     // see struct in_addr, below
		char             sin_zero[8];  // zero this if you want to	
	} destination;

	struct in_addr {
		unsigned long s_addr;  // load with inet_aton()
	};

	//destination.sin_addr = "192.168.0.19";
	//long dest_ip[15];
	//scanf("%19[0-9.]", dest_ip);
	destination.sin_family = AF_INET;
	destination.sin_port = 2222; 
	
	

	thisSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (thisSocket < 0)
	{
		printf("\nSocket Creation FAILED!");
		return 0;
	}

	
	
}

