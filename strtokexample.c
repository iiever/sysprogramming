//stackoverflow.com/questions/21097253/how-does-the-strtok-function-in-c-work

#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "Just a test";
	const char s[] = " ";
	char *token;

	token = strtok(str, s);

	while (token != NULL) {
		printf(" %s\n", token);
		token = strtok(NULL, s);
	}

	

	return 0;
}
