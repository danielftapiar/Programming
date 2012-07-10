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
	struct addrinfo hints, *servinfo, *p;
	int socketfd, new_socketfd;
	struct sockaddr_storage their_addr;
	socklen_t sin_size;
	struct sigaction sa;
	int yes =1;
	char s[INET6_ADDRSTRLEN];
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_flags=AI_PASSIVE;

	if ( (rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	//loop through all the results and bind to the first we can
	for (p=servinfo; p!=NULL; p=p->ai_next)
	{
		if ((socketfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
			{
				perror("server:socket");
				continue;
			}
		if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			perror("setsockopt");
			exit(1);
		}

		if (bind(socketfd, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(socketfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	if (p == NULL)
	{
		fprintf(stderr, "server: failed to bind\n");
		return 2;

	}

	freeaddrinfo(servinfo);

	if (listen(socketfd, BACKLOG) == -1)
	{
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}

	printf("Server: Waiting for Connections...\n");

	while (1)
	{
		sin_size = sizeof their_addr;
		new_socketfd = accept(socketfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_socketfd == -1)
		{
			perror("accept");
			continue;

		}

		inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);

		printf("server: got connection from %s\n", s );

		if (!fork()) //this is child process
		{
			close(socketfd);//child doesn't need the listener
			if (send(new_socketfd, "Hello World!",13,0) == -1)
			{
				perror("send");
				close(new_socketfd);
				exit(0);
			}
			close(new_socketfd); //parent don't need this
		}
	}
	return 0;
}