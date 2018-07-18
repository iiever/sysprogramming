#include <stdio.h>
#include <sys/types.h>
#include <resolv.h>
#include <netinet/in.h>
#define BUFSIZE 80

int main(){
	char buffer [BUFSIZE];
	struct sockaddr_in addr;
	int sd, addr_size;
	memset(buffer,0,BUFSIZE);
	sd=socket(PF_INET,SOCKDGRAM,0);
	addr.sin_family= AF_INET;
	addr.sin_port = htons(33888);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(sd,&addr,sizeof(addr));
	addr_size =sizeof(addr);
	recvfrom(sd,buffer,BUFSIZE,0,&addr,&addr_size);

	printf("Received -> %s\n", buffer);

	close(sd);
	return 0;
	
