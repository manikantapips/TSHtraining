#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
  
int globalVar=0; /*  A global variable*/
  
int main(void) 
{ 
    int localVar = 0; 
      pid_t childPID = fork(); 
    if (childPID >= 0) // fork was successful 
    { 
        if (childPID == 0) // child process 
        { 
            printf("\n Child Process Initial Value :: localVar"
                   " = %d, globalVar = %d", localVar, 
                   globalVar); 
            localVar++; 
            globalVar++; 
            
         
        } 
        else // Parent process 
        { 
            printf("\n Parent process Initial Value :: "
                   "localVar = %d, globalVar = %d", 
                   localVar, globalVar); 
  
          } 
          }
    else // fork failed 
    { 
        printf("\n Fork failed, quitting!!!!!!\n"); 
        return 1; 
    } 
  
    return 0; 
} 
