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

int SERVER_PRT; //4284 receive from
string IP_ADR; // = "192.168.0.10"; //IP of the netbook 

void error(const char *msg)
{
	perror(msg);
	//write to syslog
	exit(1);
}


void read_config()
{
	string line;
	ifstream conf("/home/testo/projects/CAN_UDP_Server/config"); //config file location on netbook
	if (conf.is_open() < 0) //open config
	{
		error("Unable to open file");
	}
	else
	{
		while (getline(conf, line)) //read the first line and copy to 'line'
		{
			if (line == "SERVER_PRT") //if line = SERVER_PRT...
			{
				getline(conf, line); //...go to the next line and copy to 'line'...
				SERVER_PRT = atoi(line.c_str()); //...convert string in 'line' to int and copy to 'SERVER_PRT'
			}
			else if (line == "IP_ADR") // works the same as above but...
			{
				getline(conf, line);
				IP_ADR = line.c_str();// handles 'line' to 'IP_ADR' slightly differently (this took waaaay to long to figure out...)
			}
		}
		cout << "config read:" << endl;
		cout << "Source port: " << SERVER_PRT << endl;
		cout << "IP: " << IP_ADR << endl;
		conf.close();
	}
	return;
}

void bind()
{
	struct sockaddr_in server;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		error("error opening socket");
	}
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
}

int main()
{
	read_config();
	bind();
	sleep(120);
    return 0;
}