#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("./test.txt", O_RDWR|O_CREAT);
	if (fd == -1) {
		printf("error opening file");
	}
}
