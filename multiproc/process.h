/*
Jeff Foster
process.h
 */

#define process_H


typedef struct process process;

struct process {
	int pid; // pid for the process 
	int memSize; // memory value
	int numCycles;
int arrivalTime;	// cpu cycle value indicator
	
};

process *new_process (int pid, int numCycles, int memSize);
//creates new process data structure



int process_getPID (process *p);
//returns the process ID

int process_getNumCycles (process *p);
//returns cycle value

int process_getMemSize (process *p);
// returns memsize



void process_printCSV (process *p);
// prints all information in the process data structure

