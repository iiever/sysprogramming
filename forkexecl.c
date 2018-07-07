#include <unistd.h>

int main() {
	int pid = fork();

	if (pid==0) {
		printf("I am parent\n");
	} else {
		sleep(2);
		execl("/bin/ls", "ls", "-l", "/root", NULL);
		//execl("/bin/cat", "cat", "./test.txt",NULL);
		//execl("/bin/ls", "ls", NULL);
	}
	return 0;
} 
