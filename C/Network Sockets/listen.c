#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MYPORT "3490"
#define BACKLOG 10


int main(int argc, char const *argv[])
{
	struct addrinfo hints, *res;
	struct sockaddr_storage their_addr, *buffer;
	socklen_t addr_size;
	int socketfd , new_socketfd, status;



	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;


	status=getaddrinfo(NULL, MYPORT, &hints, &res);
	printf("Get Address Info:%d\n",status);

	status=socketfd=socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	printf("Socket Descriptor: %d\n",status);

	status=bind(socketfd, res->ai_addr, res->ai_addrlen);
	printf("Port Bind: %d\n",status);
	
	status=listen(socketfd, BACKLOG);
	printf("Listening: %d\n",status);

	addr_size = sizeof their_addr;
	new_socketfd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);

	printf("1\n");
	recv(new_socketfd, &buffer, sizeof *buffer,0);

	printf("2\n");
	close(new_socketfd);
	close(socketfd);

	return 0;
}