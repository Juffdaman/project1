/*
Jeff Foster
process manager
 */
 #include <stdio.h>
#include "process.h"
#include <stdlib.h>


//data structure for process with required fields:




// creates new process,  assigns information from data structure
process *new_process (int pid, int numCycles, int memSize) {
	process *this = (process *) calloc (1, sizeof(process));
	this->pid = pid;
	this->numCycles = numCycles;
	this->memSize = memSize;	
	return this;
}

//
//

//returns memory footprint size
int process_getMemSize (process *p) { 
	if (!p) return 0;
	return p->memSize; 
}

//returns number of cycles for print
int process_getNumCycles (process *p) {	
	if (!p) return 0;
	return p->numCycles; 
}

//returns pid for print
int process_getPID (process *p) {
	if (!p) return -1; 
	return p->pid; 
}





//used by processlist to print to console
void process_printCSV (process *p) {
	printf("%d, %d\n", p->pid, p->numCycles);
}
