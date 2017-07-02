/*
 * jeff foster
 * Processlist
 */
#include "process.h"
#include "processlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_MEM_B 100000
#define MIN_MEM_B 1000
#define MEAN_MEM_B 20000
#define PI 3.141592654

// distributes in a non-uniform manner.
//As a result, the mean might be slightly off the desired mark.
int parrival=0;
//
typedef struct ProcessNode ProcessNode;
struct ProcessNode {
	process *process;
	ProcessNode *next;
};


/*
int gaussrand()
{
	static double U, V;
	static int phase = 20000;
	double Z;
int lol;
	if(phase == 0) {
		U = (rand() + 1.) / (100000 + 2.);
		V = rand() / (100000 + 1.);
		Z = sqrt(-2 * log(U)) * sin(2 * PI * V);
	} else
		Z = sqrt(-2 * log(U)) * cos(2 * PI * V);

	phase = 1 - phase;

	return Z;
}
*/

//data structure for the process table
struct processlist {
	
	ProcessNode *head; 
	ProcessNode *tail; 
	int totalMemory; 
	int numProcesses; 
	int totalCycles; 
	
};


void processlist_printInfo (processlist *pt) {
	if (!pt) return;
	printf("Processes: %d\nAverage # of cycles: %d\nAverage Memory footprint: %d\n",
		pt->numProcesses,
		pt->totalCycles/pt->numProcesses,
		pt->totalMemory/pt->numProcesses);
}

//prints the table







void processlist_roundrobin (processlist *pt) {
	int remaining_work;
	int array[51];
	int total=0;
	int time=0;
	int conswitch=0;
	int lastran=1;
	int test=0;
	if (!pt) return;
	ProcessNode *p;
	
	
	


	
//print processes for debugging
	for (p=pt->head; p != NULL; p=p->next) {
		process_printCSV(p->process);
		total=total+p->process->numCycles;
		printf("total %d\n", total);
	}
	
	
	//Begin round robin
	//while some process has remaining cycles
	while(total>0){
		int temptime=0;
		//go through processes
		for (p=pt->head; p != NULL; p=p->next)

			{
				// if the process has arrived and has remaining cycles
		if (time>=p->process->arrivalTime&&p->process->numCycles!=0)
		{
			// ad a context switch penalty if applicable
			if(lastran!= p->process->pid)
				
				{
					temptime=temptime+10;
					conswitch=conswitch+10;
					printf("conswitch %d\n",conswitch);
				}
			
//reduce the remaining cycles on the process, add the cycles to the time count
	if(p->process->numCycles>50)
		{		p->process->numCycles=p->process->numCycles-50;
			total=total-50;
		temptime=temptime+50;
		printf("process %d cycletime %d\n",p->process->pid, p->process->numCycles);
		}
		
		else if(p->process->numCycles<=50)
		{		
	total=total-p->process->numCycles;
			temptime=temptime+p->process->numCycles;
	p->process->numCycles=0;
			printf("process %d cycletime %d\n",p->process->pid, p->process->numCycles);

		}
			
		
	// set process as the one most recently ran
		lastran=p->process->pid;
		}
	
	
	
	
	
		}
		
		// apply the time count at the end, to ensure processes which haven't been scheduled don't run
		time=temptime+time;
test++;
	}
}



//makes the new process table
processlist *new_processlist (int numProcesses) {
	processlist *this = (processlist *) calloc (1, sizeof(processlist));


	srand(time(NULL));
	
	int i;
	for (i=0; i<numProcesses; i++) {
		if (processlist_generateNewProcess(this)) {
			this->numProcesses++;
		}
		else {
			printf("Error creating process %d\n", i);
		}
	}
	
	return this;
}



//generates random number with specified mean
int generateNumCycles () {	
	return (rand() % (11000 - 1000)) + 1000;
}

//generates memory size based on mean
//if random number generated is greater than desired mean, a value lower than the mean is produced.
// the inverse occurs if the number is lower than the mean;
// this ensures that the values generated will tend towards the mean;
int generateMemSize () {
	int upperbound;
	int lowerbound;
	int mean;
	

	
	
	// Get a number under the mean
	if ((rand() % (100000 - 1000)) > (20000 - 1000)) 
		return (rand() % (20000 - 1000)) + 1000;
	// Get a number over the mean
	else 
		return (rand() % (100000 - 20000)) + 20000;

	
	
	//return(gaussrand());
}

// generates process and appends it to table
int processlist_generateNewProcess (processlist *pt) {
	
	
	
	ProcessNode *newNode = (ProcessNode *) calloc (1, sizeof(ProcessNode));
	//Creates a new item
	if (!newNode) return -1;
		
	// 1st element is being added
	if (pt->head == NULL && pt->tail == NULL) {
		// Create new process
		process *newprocess = new_process (1, generateNumCycles(), generateMemSize());
		newprocess->arrivalTime=parrival;
			parrival=parrival+50;
		if (!newprocess) return -1;
		
		// Set the values in the process node
		newNode->process = newprocess;
		
		newNode->next = NULL;
				
		// 1st element becomes head
		pt->head = newNode;
		pt->tail = newNode;
		pt->totalCycles += process_getNumCycles(newprocess);
		pt->totalMemory += process_getMemSize(newprocess);
		
		// Return the new process id
		return process_getPID(newprocess);
	}
	// if something already exists in the table
	else if (pt->tail) {
		// Create new process		
		process *newprocess = new_process (process_getPID(pt->tail->process)+1, generateNumCycles(), generateMemSize());
		newprocess->arrivalTime=parrival;
		parrival=parrival+50;
		if (!newprocess) return -1;
	
		// Set the values in the process node
		newNode->process = newprocess;
		//newNode->prev = pt->tail;
		newNode->next = NULL;
		
		// Add the new node to the process table
		pt->tail->next = newNode;
		pt->tail = newNode;
		pt->totalCycles += process_getNumCycles(newprocess);
		pt->totalMemory += process_getMemSize(newprocess);
		
		// Return the new process
		return process_getPID(newprocess);
	}

	
	return -1;
}








