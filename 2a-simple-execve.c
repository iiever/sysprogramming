#include <stdio.h>

void main() {
	char *param[3];
	param[0] = "/bin/ls";
	param[1] = "-l";
	param[2] = "/root";
	param[3] = NULL;

	execve(param[0], param, NULL);
	exit(0);
}
