#include "processlist.h"
#include <stdio.h>
int main () {
	
	// Create process table
	
	
	
	
	
	

	//prints table information
	//processlist_fifo (pt1,13);
	//processlist_fifo (pt2,13);
	//processlist_fifo (pt3,12);
	//processlist_fifo (pt4,12);
	int process_number=13;
	processlist *pt1 = new_processlist(13);
	
	
	processlist_fifo(pt1,13);
	processlist_fifo(pt1,13);
	processlist_fifo(pt1,12);
	processlist_fifo(pt1,12);
	
	
	processlist_roundrobin(pt1,13);
	processlist_roundrobin(pt1,13);
	processlist_roundrobin(pt1,12);
	processlist_roundrobin(pt1,12);
	
	
	
	
	//processlist_printInfo(pt1);
	
	return 0;
}
