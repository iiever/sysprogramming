#include <unistd.h>

int main() {
	int ret = execl("/bin/ls", "ls", NULL);
	if(ret == -1){
		perror("error\n");
	}
	return 0;
}
