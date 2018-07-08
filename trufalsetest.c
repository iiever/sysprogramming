#include <stdio.h>
#include <stdbool.h>

int main() {
	bool isTrue = true;
	char t[]="23";
	char v[]="235";

	int size = sizeof(t);
	printf("%d\n",size);

	size = sizeof(v);
	printf("%d\n",size);


	return 0;
}
