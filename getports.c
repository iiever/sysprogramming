#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* Prints the environment, one environment variable to a line, of the
process given by PID. */

int main ()
{
	int fd;
	char filename[] = "/proc/net/tcp";
	char results[8192];
	size_t length;
	const char sep[] = " ";
	char *token;

	/* Read the contents of the file. */
	fd = open (filename, O_RDONLY);
	length = read (fd, results, sizeof (results));
	close (fd);

	/* read does not NUL-terminate the buffer, so do it here. */
	results[length] ='\0';
	printf("%s\n", results);

	token = strtok(results,sep);
	while (token != NULL) {
		printf("%s\n", token);
		token =	strtok(NULL, sep);
	}

	return 0;
}

