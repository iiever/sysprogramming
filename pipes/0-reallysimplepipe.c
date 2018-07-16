#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	int fd[2];
	pipe(fd);
	
	char msg[] = "Hello world\n";

	int pid = fork();

	if(pid==0) {
		write(fd[1], msg, 11);

	} else {
		char buff[100]={0};
		read(fd[0], buff, sizeof(buff));
		printf("buff: %s\n", buff);

	}
}
