#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	int fd[2];
	pipe(fd);
	
	char msg[] = "Hello world\n";

	int pid = fork();

	if(pid==0) {
		close(fd[0]);
		write(fd[1], msg, (strlen(msg)+1));
		exit(0);
	} else {
		char buff[100];
		close(fd[1]);
		read(fd[0],buff, sizeof(buff));
		printf("buff: %s\n", buff);
		wait(NULL);
	}
}
