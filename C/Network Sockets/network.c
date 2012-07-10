

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


/* important Structures

struct addrinfo {
	int     			ai_flags; 	    //AI_PASSIVE, AI_CANONNAME, ETC. 
	int 				ai_family;		//AF_INET, AF_INET6, AF_UNSPEC
	int 				ai_socktype;  	//SOCK_STREAM, SOCK_DGRAM
	int 				ai_protocol; 	//USE 0 FOR "any"
	int 				ai_addrlen; 	//size of ai_addr in bytes
	struct sockaddr 	*ai_addr; 		//struct sockaddr _in or _in6
	char 				*ai_canonname; 	//full canonical hostname

	struct addrinfo 	*ai_next; 		//linked list, next node;
};
struct sockaddr { //this structure can and should be casted to sockaddr_in or sockaddr_in6
	
	unsigned short 		sa_family;		// address family, AF_xxx
	char				sa_data[14]; 	//14 bytes of protocol address
};
struct sockaddr_storage {	
	sa_family_t 		ss_family;		//address family
}
//IPv4 only structures
struct sockaddr_in {
	
	short int 			sin_family; 	//Address family
	unsigned short int  sin_port;		//Port Number
	struct in_addr 		sin_addr; 		//Internet Address
	unsigned char		sin_zero[8]		//Same size as struct sockaddr
};

struct in_addr{
	uint32_t 			s_addr;			//32bit int (4 bytes)
};


//IPv6 only Structures
struct sockaddr_in6 {
	u_int16_t			sin6_family;	//address family, AF_INET6
	u_int16_t			sin6_port;		//port number, Network Byte Order
	u_int32_t			sin6_flowinfo;	//IPv6 flow information
	struct in6_addr		sin6_addr;		//IPV6 address
	u_int32_t			sin6_scope_id;	//Scope ID
};
struct in6_addr {
	unsigned char 		s6_addr[16];	//IPv6 address
};
*/

int main(int argc, char const *argv[])
{

	int status_0, status_1;
	struct addrinfo hints_0, hints_1;
	struct addrinfo *main_addressINFO, *servinfo; //will point to the results
	//struct addrinfo *p;
	struct sockaddr_in ipv4_data;
	char ipstring[INET_ADDRSTRLEN];
	struct sockaddr_in *ipv4;



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




//inet_pton(ADDRESS_TYPE, WHERE TO FIND THE STRING, WHERE TO SAVE IT)
	/*if(inet_pton(AF_INET, argv[1], &(ipv4_data.sin_addr)) > 0)
	{
		//inet_ntop(ADDRESS TYPE, WHERE THE BINARY IP IS LOCATED, WHERE TO SAVE THE IP AS A STRING, LENGTH OF THE STRING);
		inet_ntop(AF_INET, &(ipv4_data.sin_addr), ip4, INET_ADDRSTRLEN);
		fprintf(stderr, "The IPv4 address is: %s \n", ip4);
		
	}
	*/



//getaddrinfo(URL OR IP, SERVICE: HTTP/FTP ETC, STRUC HINTS, ADDRINFO)
	if ((status_0 = getaddrinfo(argv[1], "80" , &hints_0 , &main_addressINFO) ) != 0)
	{
		fprintf(stderr, "Error!\n");

		return 2;
	}

	status_1 = getaddrinfo("192.168.0.2", "80", &hints_1, &servinfo);
	if (servinfo->ai_family==AF_INET)
	{
		ipv4 = (sockaddr_in *) servinfo->ai_addr;

	}


	freeaddrinfo(main_addressINFO);
	freeaddrinfo(servinfo);
	
/*

	printf("IP addresses for %s: \n \n", argv[1]);

	for (p=servinfo; p!=NULL; p=p->ai_next)
	{
		void *addr;
		char *ipver;
		if (p->ai_family == AF_INET)
		{
			struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}

	}

	inet_ntop (p->ai_family, addr, ipstr, sizeof ipstr);
	printf("%s  %s \n", ipver, ipstr);
*/
	//freeaddrinfo(servinfo);

	
	return 0;
}