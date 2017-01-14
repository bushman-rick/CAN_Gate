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

const int FIFO_BUFF = 1024;

string readFifo()
{
	int fd = -1;
	const char *fifo = "/home/testo/projects/fifo";
	char buff[FIFO_BUFF];

	/* open, read, and display the message from the FIFO */
	while (fd < 0)
	{
		fd = open(fifo, O_RDONLY);
	}
	read(fd, buff, FIFO_BUFF);
	cout << "Read from FIFO: " << buff << endl;
	close(fd);

	//transmit()

	return "gooballs";
}

int main()
{
	for (int i = 0; i < 150; i++)
	{
		cout << readFifo() << " " << i << endl;
		sleep(1);
	}
    return 0;
}