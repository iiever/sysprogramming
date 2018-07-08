#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool isItNumber(char* s, int size) {
	int notisnumbercount = 0;
	int i;
	printf("size of %s is %d\n",s,size);

	for (i=0; i<size-1; i++) {
		if(!isdigit(s[i]) && !isspace(s[i])) notisnumbercount++;
	}

	if(notisnumbercount > 0) return false;
	else return true;	

}
