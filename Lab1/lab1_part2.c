#include <stdio.h>

int main(){
    int mainpid = getpid();
    printf ("Root PID: %d\n", mainpid);
    int i,j;
    for (i = 0; i < 2 && mainpid == getpid(); i++){
	if (fork() != 0){
	    waitpid(-1, NULL, 0);
	}
	else{
	    for (j = 0; j < 2; j++){
		if (fork() != 0){
		    waitpid(-1, NULL, 0);
		    printf("Parent of %d is: %d\n", getpid(), getppid());
		}
		else{
		    printf("Child is: %d and parent is: %d\n", getpid(), getppid());
		    break;
		}
	    }
	}
    }
}
