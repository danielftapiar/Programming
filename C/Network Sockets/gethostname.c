#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
	size_t size= sizeof size;
	char hostname[size];

	gethostname(&hostname,size);
	printf("%s\n", hostname);
	return 0;
}