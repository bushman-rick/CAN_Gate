


/*
Function:
Receive parsed CAN packet from CAN to Ethernet Gateway from 192.168.0.10:4284
Parse CAN packet
Check is UDP_Telemetry is started, if not, start it
Write to FIFO
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

int SERVER_PRT; //4284
int CLIENT_PRT; //8352
const char* IP_ADR = "192.168.0.10"; 

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

void read_config() 
{
	string line;
	ifstream conf("config"); //~/projects/CAN_UDP_Server/config
	if (conf.is_open())
	{
		while (getline(conf, line))
		{
			if (line == "SERVER_PRT")
			{
				getline(conf, line);
				SERVER_PRT = atoi(line.c_str()); //convert string to int
			}
			else if (line == "CLIENT_PRT")
			{
				getline(conf, line);
				CLIENT_PRT = atoi(line.c_str()); //convert string to int
			}
			else if (line == "IP_ADR")
			{
				getline(conf, line);
				//IP_ADR = line.c_str(); //convert string to const char* //// I couldnt get this to work ie read the ip from the file 
			}
		}
		cout << "config read:" << endl;
		//cout << "Destination port: " << SERVER_PRT << endl;
		cout << "Source port: " << CLIENT_PRT << endl;
		cout << "IP: " << IP_ADR << endl;
		conf.close();
	}
	else cout << "Unable to open file";
	// write to syslog()
	// kill server
	return;
}

void receive(char resp)
{
	char _resp = resp;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		cout << "error opening socket" << endl;
	}

	int enable = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		error("setsockopt(SO_REUSEADDR) failed");

	struct sockaddr_in server , client;

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP_ADR);
	server.sin_port = htons(SERVER_PRT);

	//memset(&client, 0, sizeof(client));
	//client.sin_family = AF_INET;
	//client.sin_addr.s_addr = inet_addr(IP_ADR);
	//client.sin_port = htons(CLIENT_PRT);


	char buffer[256];
	//socklen_t c_size = sizeof(client);
	socklen_t s_size = sizeof(server);


	///////////////////////////// v bind socket v
	if (bind(sockfd, (struct sockaddr*) &server, s_size) < 0)
	{
		error("bind error");
		// write to syslog()
		// kill server
		//return;
	}
	///////////////////////////// ^ bind socket ^

	/*
	///////////////////////////// v Listen v

	int LISTEN_BACKLOG = 100;
	if (listen(sockfd, LISTEN_BACKLOG) < 0)
	{
		error("listen failed");
		// write to syslog()
		// kill server
		//return;
	}

	///////////////////////////// ^ Listen ^

	///////////////////////////// v Accept() v

	if (accept(sockfd, (struct sockaddr *)&server, &s_size) < 0)
	{
		error("accept failed");
		// write to syslog()
		// kill server
		//return;
	}

	///////////////////////////// ^ Accept() ^
	*/

	int count = 0;
	cout << "\nReceiving from IP: " << IP_ADR << " Port: " << SERVER_PRT << endl;

	while (_resp == 'y')
	{
		count++;
	
		///////////////////////////// v receive v

		if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server, &s_size) < 0)
		{
			cout << "ERROR READING FROM SOCKET";
			// write to syslog()
			// kill server
			return;
		}

		///////////////////////////// ^ receive ^

		///////////////////////////// v Parse CAN packet v

		cout << "Packet #" << count << "; Data: " << buffer << endl;
		
		///////////////////////////// ^ Parse CAN packet ^

		///////////////////////////// v UDP_Telemetry check v

		///////////////////////////// ^ UDP_Telemetry check ^

		///////////////////////////// v Write to FIFO v

		///////////////////////////// ^ Write to FIFO ^

	}
	

	close(sockfd);
}
int main()
{
	///////////////////////////// v reads config file v
	// reference: http://www.cplusplus.com/doc/tutorial/files/
	read_config();

	///////////////////////////// ^ reads config file ^

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
