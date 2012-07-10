#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
	int socketfd;
	struct addrinfo hints;
	struct addrinfo *res;
	void *addr;
	unsigned short int port_number;

	memset(&hints, 0 , sizeof hints);
	hints.ai_family=AF_INET;
	hints.ai_socktype=SOCK_STREAM;
	
	
	struct sockaddr_in *ipv4;
	char ipv4String[INET_ADDRSTRLEN];
//	char portString[5];

	
	getaddrinfo("www.gameinformer.com", "80", &hints, &res);
printf("asdf\n");
	ipv4 = (struct sockaddr_in *) res->ai_addr;
	
	addr = &(ipv4->sin_addr);
	port_number = ipv4->sin_port;


	inet_ntop(res->ai_family, addr, ipv4String, sizeof ipv4String);
//	inet_ntop(res->ai_family, port, portString, sizeof portString);
	
	fprintf(stderr, "IPV4: %s\n", ipv4String);
	fprintf(stderr, "Port: %d\n", port_number);

//connect

	socketfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	connect(socketfd, res->ai_addr, res->ai_addrlen);





	return 0;
}