#include "portmonitor.h"
#include <stdio.h>

int main() {
	for(;;) {
		checkPort();
		sleep(1);
	}
}
