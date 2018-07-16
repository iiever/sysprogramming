#include <unistd.h>

int main() {
	int ret = execl("/bin/ls", "ls", "-l", (char *)0);
	if(ret == -1){
		perror("error\n");
	}
	return 0;
}
