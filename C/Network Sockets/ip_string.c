#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int main(int argc, char const *argv[])
{

	int status_0, status_1;
	struct addrinfo hints_0, hints_1;
	struct addrinfo *main_addressINFO, *servinfo;
	//struct sockaddr_in ipv4_data;
	char ipstring[INET_ADDRSTRLEN];
	struct sockaddr_in *ipv4;
	char *ipver = "IPv4";
	void *addr;
	char *port;


	if (argc != 2)
	{
		fprintf(stderr, "error: Insert only one parameter \n");
		return 1;
	}

	memset(&hints_0, 0 , sizeof hints_0);
	hints_0.ai_socktype= SOCK_STREAM; //TCP Stream
	hints_0.ai_family=AF_INET;	//address type = IPv4

	memset(&hints_1, 0 , sizeof hints_1);
	hints_1.ai_socktype=SOCK_STREAM;
	hints_1.ai_family=AF_INET;
	hints_1.ai_flags = AI_PASSIVE;

	if ((status_0 = getaddrinfo(argv[1], "23" , &hints_0 , &main_addressINFO) ) != 0)
	{
		fprintf(stderr, "Error!\n");

		return 2;
	}

	ipv4 = (struct sockaddr_in *) main_addressINFO->ai_addr;
	addr = &(ipv4->sin_addr);

	inet_ntop(main_addressINFO->ai_family, &(ipv4->sin_port), port, sizeof port);

	inet_ntop(main_addressINFO->ai_family, addr, ipstring, INET_ADDRSTRLEN);

	fprintf(stderr, "%s: %s\nPort: %s\n", ipver,  ipstring, port);

	status_1 = getaddrinfo("192.168.0.3", "80", &hints_1, &servinfo);

	if (servinfo->ai_family==AF_INET)
	{
		

		ipv4 = (struct sockaddr_in *) servinfo->ai_addr;
		addr = &(ipv4->sin_addr);
		ipver = "IPv4";

	}

	inet_ntop(servinfo->ai_family, addr, ipstring, sizeof ipstring);
	fprintf(stderr, "%s: %s\n", ipver, ipstring );



	freeaddrinfo(main_addressINFO);
	freeaddrinfo(servinfo);

	return 0;
}
