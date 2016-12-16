// reference http://www.cplusplus.com/forum/unices/76180/
// reference http://www.microhowto.info/howto/listen_for_and_receive_udp_datagrams_in_c.html
// reference http://stackoverflow.com/questions/9843281/c-inet-noob-what-am-i-doing-wrong

/*
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

using namespace std;

void error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
int main()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	struct sockaddr_in serv;

	serv.sin_family = AF_INET;
	serv.sin_port = htons(8353);
	serv.sin_addr.s_addr = inet_addr(INADDR_ANY);

	char buffer[256];
	//__socklen_t l = sizeof(client);
	//socklen_t m = client;
	cout << "\ngoing to recv\n";
	int rc = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serv, 0);

	bind(sockfd, (sockaddr*)&serv.sin_addr, sizeof(serv));
	if (rc<0)
	{
		cout << "ERROR READING FROM SOCKET";
	}
	/*
	cout << "\n the message received is : " << buffer << endl;
	int rp = sendto(sockfd, "hi", 2, 0, (struct sockaddr *)&client, l);

	if (rp<0)
	{
		cout << "ERROR writing to SOCKET";
	}
	
}
*/

/*!
* Simple chat program (server side).cpp - http://github.com/hassanyf
* Version - 2.0.1
*
* Copyright (c) 2016 Hassan M. Yousuf
*/

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
	/* ---------- INITIALIZING VARIABLES ---------- */

	/*
	1. client/server are two file descriptors
	These two variables store the values returned
	by the socket system call and the accept system call.
	2. portNum is for storing port number on which
	the accepts connections
	3. isExit is bool variable which will be used to
	end the loop
	4. The server reads characters from the socket
	connection into a dynamic variable (buffer).
	5. A sockaddr_in is a structure containing an internet
	address. This structure is already defined in netinet/in.h, so
	we don't need to declare it again.
	DEFINITION:
	struct sockaddr_in
	{
	short   sin_family;
	u_short sin_port;
	struct  in_addr sin_addr;
	char    sin_zero[8];
	};
	6. serv_addr will contain the address of the server
	7. socklen_t  is an intr type of width of at least 32 bits
	*/
	int client, server;
	int portNum = 4283;
	bool isExit = false;
	int bufsize = 1024;
	char buffer[bufsize];

	struct sockaddr_in server_addr;
	socklen_t size;

	/* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
	/* --------------- socket() function ------------------*/

	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0)
	{
		cout << "\nError establishing socket..." << endl;
		exit(1);
	}

	/*
	The socket() function creates a new socket.
	It takes 3 arguments,
	a. AF_INET: address domain of the socket.
	b. SOCK_STREAM: Type of socket. a stream socket in
	which characters are read in a continuous stream (TCP)
	c. Third is a protocol argument: should always be 0. The
	OS will choose the most appropiate protocol.
	This will return a small integer and is used for all
	references to this socket. If the socket call fails,
	it returns -1.
	*/

	cout << "\n=> Socket server has been created..." << endl;

	/*
	The variable serv_addr is a structure of sockaddr_in.
	sin_family contains a code for the address family.
	It should always be set to AF_INET.
	INADDR_ANY contains the IP address of the host. For
	server code, this will always be the IP address of
	the machine on which the server is running.
	htons() converts the port number from host byte order
	to a port number in network byte order.
	*/
	server_addr.sin_family = AF_INET;
	//server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_addr.s_addr = inet_addr("192.168.0.20");
	server_addr.sin_port = htons(portNum);

	/* ---------- BINDING THE SOCKET ---------- */
	/* ---------------- bind() ---------------- */


	if ((bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0)
	{
		cout << "=> Error binding connection, the socket has already been established..." << endl;
		return -1;
	}

	/*
	The bind() system call binds a socket to an address,
	in this case the address of the current host and port number
	on which the server will run. It takes three arguments,
	the socket file descriptor. The second argument is a pointer
	to a structure of type sockaddr, this must be cast to
	the correct type.
	*/

	size = sizeof(server_addr);
	cout << "=> Looking for clients..." << endl;

	/* ------------- LISTENING CALL ------------- */
	/* ---------------- listen() ---------------- */

	listen(client, 1);

	/*
	The listen system call allows the process to listen
	on the socket for connections.
	The program will be stay idle here if there are no
	incomming connections.
	The first argument is the socket file descriptor,
	and the second is the size for the number of clients
	i.e the number of connections that the server can
	handle while the process is handling a particular
	connection. The maximum size permitted by most
	systems is 5.
	*/

	/* ------------- ACCEPTING CLIENTS  ------------- */
	/* ----------------- listen() ------------------- */

	/*
	The accept() system call causes the process to block
	until a client connects to the server. Thus, it wakes
	up the process when a connection from a client has been
	successfully established. It returns a new file descriptor,
	and all communication on this connection should be done
	using the new file descriptor. The second argument is a
	reference pointer to the address of the client on the other
	end of the connection, and the third argument is the size
	of this structure.
	*/

	int clientCount = 1;
	server = accept(client, (struct sockaddr *)&server_addr, &size);

	// first check if it is valid or not
	if (server < 0)
		cout << "=> Error on accepting..." << endl;

	while (server > 0)
	{
		strcpy(buffer, "=> Server connected...\n");
		send(server, buffer, bufsize, 0);
		cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
		cout << "\n=> Enter # to end the connection\n" << endl;

		/*
		Note that we would only get to this point after a
		client has successfully connected to our server.
		This reads from the socket. Note that the read()
		will block until there is something for it to read
		in the socket, i.e. after the client has executed a
		the send().
		It will read either the total number of characters
		in the socket or 1024
		*/

		cout << "Client: ";
		do {
			recv(server, buffer, bufsize, 0);
			cout << buffer << " ";
			if (*buffer == '#') {
				*buffer = '*';
				isExit = true;
			}
		} while (*buffer != '*');

		do {
			cout << "\nServer: ";
			do {
				cin >> buffer;
				send(server, buffer, bufsize, 0);
				if (*buffer == '#') {
					send(server, buffer, bufsize, 0);
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');

			cout << "Client: ";
			do {
				recv(server, buffer, bufsize, 0);
				cout << buffer << " ";
				if (*buffer == '#') {
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
		} while (!isExit);

		/*
		Once a connection has been established, both ends
		can both read and write to the connection. Naturally,
		everything written by the client will be read by the
		server, and everything written by the server will be
		read by the client.
		*/

		/* ---------------- CLOSE CALL ------------- */
		/* ----------------- close() --------------- */

		/*
		Once the server presses # to end the connection,
		the loop will break and it will close the server
		socket connection and the client connection.
		*/

		// inet_ntoa converts packet data to IP, which was taken from client
		cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
		close(server);
		cout << "\nGoodbye..." << endl;
		isExit = false;
		exit(1);
	}

	close(client);
	return 0;
}