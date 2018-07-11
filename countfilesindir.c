#include <stdio.h>

int main(int argc, char* argv[]) {
	char cmdstr[128] = {0};

	sprintf(cmdstr, "%s  %s %s", "ls ", argv[1], "| wc -l");
	system(cmdstr);
	printf("%s\n", cmdstr);
	return 0;
}
