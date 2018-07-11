/*
 * Assumes there is only one tcp line when you do netstat -tan
 * reads from /proc/net/tcp
 * discards the first line which are merely headers
 * retains second line and extracts the local ip, local port, remote ip, remote port
 *
 * Paul Chin
 * 8-July-2018
 *
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include "hextoIP.h"  //make sure this file is in same folder


void extractIpAndPort(char* ip, int* port, char* line, char* separator){
	int i=0;
	char* token;

	char localipport[2][64];
	token = strtok(line,separator);
	while (token != NULL) {
		strcpy(localipport[i],token);
		token =	strtok(NULL, separator);
		i++;
	}

	*port = strtol(localipport[1], NULL, 16);
	strcpy(ip,hextoIP(localipport[0]));

	return;
}

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

	// Read the contents of the file /proc/net/tcp
	fd = open (filename, O_RDONLY);
	length = read (fd, results, sizeof (results));
	close (fd);

	// read does not NUL-terminate the buffer, so do it here. 
	results[length] ='\0';

	// split 1st and 2nd lines
	// 1st line are merely headers, we need 2nd line
	token = strtok(results,sep);
	while (token != NULL) {
		strcpy(lines[i++],token);
		token =	strtok(NULL, sep);
	}

	printf("1st line:\n %s\n", lines[0]);
	printf("2nd line:\n %s\n", lines[1]);

	// 2nd contains ip and port numbers, we split them by spaces
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

	// we extract the local ip, local port and remote ip and remote port
	char locIP[64];
	int localPt;
	char remIP[64];
	int remotePt;

	struct in_addr addr;
	
	const char sepcolon[] = ":";
	extractIpAndPort(locIP, &localPt, linenums[1], sepcolon);
	
	printf("\nLocal IP: %s, Local Port: %d\n\n",locIP, localPt);

	extractIpAndPort(remIP, &remotePt, linenums[2], sepcolon);
	printf("\nRemote IP: %s, Remote Port: %d\n\n",remIP, remotePt);

	if(strcmp(remIP, "0.0.0.0") != 0) {
		printf("Connection alert from: %s\n", remIP);
	}

	return 0;
}

