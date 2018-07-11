#include <unistd.h>

int main() {
	int pid = fork();
	int childstatus;
	int pidended;

	if (pid==0) {
		printf("I am child, my fork returns pid: %d\n", pid);
		printf("getpid: %d\n", getpid());
	} else {
		printf("I am parent my fork returns pid: %d\n", pid);
		printf("getpid: %d\n", getpid());
		pidended = wait(&childstatus);
		printf("pid %d ended with status: %d\n", pidended,childstatus);
	}
	return 0;
} 
