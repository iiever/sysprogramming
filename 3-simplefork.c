#include <unistd.h>

int main() {
	int pid = fork();

	if (pid==0) {
		printf("I am child, my fork returns pid: %d\n", pid);
		printf("getpid: %d\n", getpid());
	} else {
		printf("I am parent my fork returns pid: %d\n", pid);
		printf("getpid: %d\n", getpid());
	}
	return 0;
} 
