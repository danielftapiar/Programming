#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define PORT "3490"
#define BACKLOG 10
#define MAXDATASIZE 100 //max number of bytes we can get at once

void sigchld_handler(int s)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in *) sa) -> sin_addr);
	}

	return 0;

}

int main(int argc, char const *argv[])
{
	int socketfd, numbytes;
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];

	if (argc != 2)
	{
		fprintf(stderr, "usage: client hostname\n");
		exit(1);

	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;

	if ( (rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	//loop through all the results and bind to the first we can
	for (p=servinfo; p!=NULL; p=p->ai_next)
	{
		if ((socketfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
			{
				perror("client:socket");
				continue;
			}
		
		if(connect(socketfd, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(socketfd);
			perror("client: connect");
			continue;
		}

		break;
	}

	if (p==NULL)	
	{
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr), s, sizeof s);

	printf("client connecting to %s\n", s );

	freeaddrinfo(servinfo);

	if ( (numbytes=recv(socketfd,buf,MAXDATASIZE-1, 0) ) == -1 )
	{
		perror("recv");
		exit(1);

	}

	buf[numbytes] = '\0';
	printf("client: recived %s\n", buf );
	close(socketfd);
	return 0;

}