#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>


int main(int argc, char const *argv[])
{

	struct addrinfo hints, *res;
	int socketfd;
	

	memset(&hints, 0 , sizeof hints);
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_family=AF_UNSPEC;
	hints.ai_flags=AI_PASSIVE;

	getaddrinfo("201.214.234.44", "41967", &hints, &res);
	
	socketfd=socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
	connect(socketfd, res->ai_addr, res->ai_addrlen);

	
	getpeername(socketfd, &res, sizeof (struct sockaddr));

	close(socketfd);



	return 0;
}