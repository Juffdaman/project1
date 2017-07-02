/*
Jeff Foster
processlist.h
header for the processlist program
 */




typedef struct processlist processlist;

//creates process table with a initial process number
processlist *new_processlist (int numProcesses);






int processlist_generateNewProcess (processlist *pt);



void processlist_printInfo (processlist *pt);
//print the number of processes, the average cycles, and the average memory usage

void processlist_roundrobin (processlist *pt);


void processlist_fifo (processlist *pt);