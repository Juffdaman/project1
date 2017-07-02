

Jeff Foster
Daniel Morgan
CSCE 4600
Project 1


compile with:
gcc *.c
run with:
./a.out

Program provides non uniform distribution of means for memory footprint and cycle values. 
As such, the values might be slightly off the mark, but they still tend to the required means. 

I used 2 main data structures:
A process structure which contains the required tuples (ID, # of cycles, memory footprint, and arrival time) and
a larger processlist data structure, which stores info for all of the processes (in  linked list format) as well as information regarding the averages


The program exploits the central limit theorem(CLT).
The program generates random values for the cycle count. Since the desired mean is min+(max-min)/2, 
the CLT suggests that the resulting random value will tend to 6000.
Memory footprint mean is achieved by extending this idea, by essentially making the chances that you will get a number above or below the mean equally likely.
Memory is measured in bytes (20000 target mean)
Analysis
=============
 Program is reasonably accurate for large data sets (between 1000 and 10000), with tests being within 50 cycles and within 1 kb of the target means for clock cycles and memory footprint, respectively.
Graphs containing the distribution for 1000 processes (Cyclecount and memoryfootprint .jpeg) are included.
