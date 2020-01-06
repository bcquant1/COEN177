#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    char str[10];
    char str_exit[10] = "exit";

    while(1){
	printf ("Type in a command \n");
	scanf ("%s", str);
	if (strcmp (str, str_exit) == 0){
	    return 0;
	} 
	else{
	    if (fork() != 0){
		waitpid(-1, NULL, 0);
	    }
	    else{
		execve("hello", NULL, NULL);
	    }
	    
	}
    }
}


