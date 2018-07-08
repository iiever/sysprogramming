#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
//#include "isitnumber.h"
//#include "splitnewline.h"
#include <arpa/inet.h>
#include "hextoIP.h"

int main ()
{
	int fd;
	char filename[] = "/proc/net/tcp";
	char results[8192];
	size_t length;
	const char sep[] = "\n";
	char *token;

	char lines[2][128];
	int i=0;

	/* Read the contents of the file. */
	fd = open (filename, O_RDONLY);
	length = read (fd, results, sizeof (results));
	close (fd);

	/* read does not NUL-terminate the buffer, so do it here. */
	results[length] ='\0';

	token = strtok(results,sep);
	while (token != NULL) {
		strcpy(lines[i++],token);
		token =	strtok(NULL, sep);
	}

	printf("All lines:\n %s\n", lines[1]);

	const char sepspace[] = " ";
	char linenums[32][64];
	i=0;
	token = NULL;

	token = strtok(lines[1],sepspace);
	while (token != NULL) {
		strcpy(linenums[i],token);
		token =	strtok(NULL, sepspace);
		i++;
	}

	printf("\nSplit by space: \n\n");

	for(i=0; i<32; i++){
		if(strcmp(linenums[i],"")!=0) {
			printf("%s\n",linenums[i]);
		}
	}

	printf("\nPrint Local IP : Local Port, Remote IP: Remote Port:\n\n");

	for(i=1; i<3; i++) {
			printf("%s\n",linenums[i]);
	}

	char localIP[64];   char locIP[64];
	char localPort[64]; int localPt;
	char remoteIP[64];  char remIP[64];
	char remotePort[64]; int remotePt;

	struct in_addr addr;
	
	const char sepcolon[] = ":";
	char localipport[2][64];
	i=0;
	token = NULL;

	token = strtok(linenums[1],sepcolon);
	while (token != NULL) {
		strcpy(localipport[i],token);
		token =	strtok(NULL, sepcolon);
		i++;
	}

	strcpy(localIP, localipport[0]);
	strcpy(localPort, localipport[1]);
	localPt = strtol(localPort, NULL, 16);
	strcpy(locIP,hextoIP(localIP));
	

	printf("\nLocal IP: %s, Local Port: %d\n\n",locIP, localPt);

	i=0;
	token = NULL;

	token = strtok(linenums[2],sepcolon);
	while (token != NULL) {
		strcpy(localipport[i],token);
		token =	strtok(NULL, sepcolon);
		i++;
	}

	strcpy(remoteIP, localipport[0]);
	strcpy(remotePort, localipport[1]);
	remotePt = strtol(remotePort, NULL, 16);
	strcpy(remIP,hextoIP(remoteIP));
	printf("\nRemote IP: %s, Remote Port: %d\n\n",remIP, remotePt);

	return 0;
}

