#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


int main(){
    int mainpid1 = getpid();
    printf ("Root PID:%d\n", mainpid1);
    int i,j,k;
    for (i = 0; i < 2 && mainpid1 == getpid(); i++){ 
	if (fork() != 0){
	    waitpid(-1, NULL, 0);
	}
	else{
	    int mainpid2 = getpid();
	    printf ("PID: %d and its parent is: %d\n", mainpid2,getppid());
	    for (j = 0; j < 2 && mainpid2 == getpid(); j++){
		if (fork() != 0){
		    waitpid(-1, NULL, 0);
		}
		else{
		    for (k = 0; k < 2; k++){
			if (fork() != 0){
			    waitpid(-1, NULL, 0);
			    printf("Parent of %d is: %d\n",getpid(), getppid());
			}
			else{
			    printf("Child is: %d and parent is: %d\n", getpid(), getppid());
			    break;
			}
		    }
		}
	    }
	}
    }
}
