

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int main(int argc, char const *argv[])
{
	struct sockaddr_in ipv4_address_binary;
	char ipv4_address_string[INET_ADDRSTRLEN];

	if (inet_pton(AF_INET, argv[1], &(ipv4_address_binary)))
	{
		inet_ntop(AF_INET, &(ipv4_address_binary), ipv4_address_string, INET_ADDRSTRLEN);

		printf("%s\n", ipv4_address_string);
	}

	return 0;
}