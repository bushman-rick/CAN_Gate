#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <sys/types.h> 
#include <sys/socket.h>

int main()
{
    printf("hello from UDP_Server!\n");
	//Just going to try out sending some UDP packets
	//Tutorial: https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html

	int s = socket(AF_INET, SOCK_DGRAM, 0);
    return 0;
}