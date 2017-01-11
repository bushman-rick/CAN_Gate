/*
Function:
Receive parsed CAN packet from CAN to Ethernet Gateway from 192.168.0.10:4284
Parse CAN packet
Check is UDP_Telemetry is started, if not, start it
Write to FIFO
*/

/*
Prototype functionality:
Receive packet from test_client (receive())
Send packet to test_server(transmit())
Ignore telemCheck() & writeFifo()

*/

/*
TODO:
- send/receive data as relevant data type
- set some kind of exit condition that isnt Ctrl+C for the loop in receive()
- (done) move socket initialisation out of loop for receive() & transmit()
- (done) read IP_ADR from config file 
*/


//###########################################
//compile: "g++ server.cpp -o CAN_UDP_Server"
//###########################################

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

//int telemCheckCount = 0;             // not used for prototype

struct sockaddr_in p_client;
int p_CLIENT_PRT = 4281; //transmit to
const char* p_IP_ADR = "192.168.0.10"; //192.168.0.18 is the actual destination ip
int p_sockfd;

void error(const char *msg)
{
	perror(msg);
	//write to syslog
	exit(1);
}

//telemCheck()
/*
int telemCheck()                                                                  // not used for prototype
{
	int telemPID = 0;
	string c = "pgrep UDP_Telemetry";
	system(c.c_str());

	cout << "UDP_Telemetry PID: " << telemPID << endl;

	//read output of system(c.c_str()) somehow and assign to telemPID
	if (telemPID > 0)
	{
		//OK, good to write to FIFO
		cout << "UDP_Telemetry is running..." << endl;
		telemCheckCount = 0;
		return 1;
	}
	else
	{
		//Not OK, run UDP_Telemetry
		cout << "Starting UDP_Telemetry" << endl;
		//system("~/projects/UDP_Telemetry/UDP_Telemetry"); this doesnt work as desired
		FILE *handle = popen("~/projects/UDP_Telemetry/UDP_Telemetry &","r");
		//FILE *handle = popen("~/projects/test_client/a.out &", "r"); //for testing

		return -1;
	}
}
*/

//writeFifo()
/*
int writeFifo(string packet)                                                     //not used for prototype
{
	int temp = packet.size();
	char tBuff[temp + 1];

	for (int a = 0; a <= temp; a++)
	{
		tBuff[a] = packet[a];
	}

	int fd;
	const char *fifo = "/home/testo/projects/fifo";

	mkfifo(fifo, 0666);

	fd = open(fifo, O_WRONLY);
	write(fd, tBuff, sizeof(packet));
	close(fd);

	//remove the FIFO
	unlink(fifo);

	return 0;
}
*/

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

int transmit_init() //for prototype
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


		///////////////////////////// v bind socket v

		int sockfd;
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if (sockfd < 0)
		{
			cout << "error opening socket" << endl;
		}

		int enable = 1;
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
			error("setsockopt(SO_REUSEADDR) failed");

		struct sockaddr_in server;

		memset(&server, 0, sizeof(server));
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = inet_addr(IP_ADR.c_str());
		server.sin_port = htons(SERVER_PRT);

		char buffer[64];
		socklen_t s_size = sizeof(server);

		if (bind(sockfd, (struct sockaddr*) &server, s_size) < 0)
		{
			error("bind error");
		}
		///////////////////////////// ^ bind socket ^

		if (transmit_init() < 0)
		{
			error("transmit_init error");
		}


		///////////////////////////// v receive v
		//move the below loop into the loop and socket init outsdie of loop
		while (_resp == 'y') //edit loop so that when a particular signal is received, this program terminates??
		{
			count++;
			if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server, &s_size) < 0)
			{
				error("receive error");
				return;
			}

			///////////////////////////// ^ receive ^



			///////////////////////////// v Parse CAN packet v
			//Probably can/needs to be be expanded??

			cout << "Packet #" << count << "; Data: " << buffer << endl;

			///////////////////////////// ^ Parse CAN packet ^


			///////////////////////////// v transmit() to Android tablet v
			//for prototype

			
			if (transmit_send(buffer) < 0)
			{
				error("transmit_init error");
			}

			for (unsigned int a = 0; a <= sizeof(buffer); a++) //reset buffer
			{
				buffer[a] = '\0';
			}

			///////////////////////////// ^ transmit() to Android tablet ^
		}

		///////////////////////////// v UDP_Telemetry check v                           disabled for prototype
		//check if UDP_Telemetery (telem.cpp) is running. If not, run it.

		/* 
		if telemCheck() is good, teleCheckCount is reset to 0.
		If telemCheck is called more than 10 times, something is wrong and error() is called
		Without this check, telemCheck will spawn as many UDP_Telemetry processess as it can
		*/
		
		/*
		telemCheck();
		if (telemCheckCount < 10)
		{
			telemCheckCount++;
		}
		else
		{
			error("Could not open UDP_Telemetry. Exiting.\n");
		}
		cout << telemCheckCount << endl;
		*/

		///////////////////////////// ^ UDP_Telemetry check ^



		///////////////////////////// v Write to FIFO v                                 disabled for prototype
		//write CAN packet to FIFO for UDP_Telemetry to read
		//http://stackoverflow.com/questions/2784500/how-to-send-a-simple-string-between-two-programs-using-pipes
		
		/* 
		if (writeFifo(buffer) < 0)
		{
			error("write to fifo fail");
		}		
		*/

		///////////////////////////// ^ Write to FIFO ^

		close(sockfd);	
}
int main()
{
	//telemCheck(); //disabled for prototype

	///////////////////////////// v reads config file v
	// reference: http://www.cplusplus.com/doc/tutorial/files/
	read_config();
	///////////////////////////// ^ reads config file ^

	receive();
}