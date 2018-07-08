#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

char* hextoIP(char* hexstr) {
	struct in_addr addr;
	
	char taddr[128];

	sprintf(taddr,"0x%s",hexstr);
	printf("taddr: %s\n", taddr);


	addr.s_addr = htonl(inet_addr(taddr));
	

	char*s = inet_ntoa(addr);

	return s;
}

