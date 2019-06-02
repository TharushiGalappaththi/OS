#include <stdio.h>
int main()
{   if(fork()>0){
        
         printf("This is the Parent Process\nParent process created a child process\n");
        printf("Child process id is %d\n",getpid());
    }
    
    else if(fork()==0){
        //sleep();
        printf("\n\n\n");
        printf("This is the child process\n");
        
    printf("Child process received 0 as return value of fork()");
    }
   
   
    return 0;
}