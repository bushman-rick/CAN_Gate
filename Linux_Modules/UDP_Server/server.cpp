


/*
Function:
Receive parsed CAN packet from CAN to Ethernet Gateway from 192.168.0.10:4284
Parse CAN packet
Check is UDP_Telemetry is started, if not, start it
Write to FIFO
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
#include<sys/stat.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/stat.h.html
#include<fcntl.h> //source http://unix.superglobalmegacorp.com/Net2/newsrc/sys/fcntl.h.html

using namespace std;

int SERVER_PRT; //4284
int CLIENT_PRT; //8352
const char* IP_ADR = "192.168.0.10"; 

int telemCheckCount = 0;

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int telemCheck()
{
	int telemPID = 0;
	string c = "pgrep UDP_Telemetry";
	//string c = "pgrep t_client"; //for testing

	system(c.c_str());

	cout << "UDP_Telemetry PID: " << telemPID << endl;

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

int writeFifo(string packet)
{
	int temp = packet.size();
	char tBuff[temp + 1];

	for (int a = 0; a <= temp; a++)
	{
		tBuff[a] = packet[a];
	}

	int fd;
	const char *fifo = "/home/testo/projects/fifo";

	/* create the FIFO (named pipe) */
	mkfifo(fifo, 0666);

	/* write "Hi" to the FIFO */
	fd = open(fifo, O_WRONLY);
	write(fd, tBuff, sizeof(packet));
	close(fd);

	/* remove the FIFO */
	unlink(fifo);

	return 0;
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
		//cout << "Destination port: " << CLIENT_PRT << endl;
		cout << "Source port: " << SERVER_PRT << endl;
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

	if (bind(sockfd, (struct sockaddr*) &server, s_size) < 0)
	{
		error("bind error");
		// write to syslog()
		// kill server
	}
	///////////////////////////// ^ bind socket ^

	int count = 0;
	cout << "\nReceiving on: " << IP_ADR << " : " << SERVER_PRT << endl;

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
		*/
		cout << telemCheckCount << endl;
		///////////////////////////// ^ UDP_Telemetry check ^



		///////////////////////////// v Write to FIFO v
		//write CAN packet to FIFO for UDP_Telemetry to read
		//http://stackoverflow.com/questions/2784500/how-to-send-a-simple-string-between-two-programs-using-pipes
		
		if (writeFifo(buffer) < 0)
		{
			error("write to fifo fail");
		}		
		
		///////////////////////////// ^ Write to FIFO ^

	}
	

	close(sockfd);
}
int main()
{
	//telemCheck();

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
