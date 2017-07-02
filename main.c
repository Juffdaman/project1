#include "processlist.h"
#include <stdio.h>
int main () {
	int process_number=50;
	// Create process table
	
	
	processlist *pt1 = new_processlist(process_number);

	//prints table information
	processlist_roundrobin(pt1);
	processlist_printInfo(pt1);
	
	return 0;
}
