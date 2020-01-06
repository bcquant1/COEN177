#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
    //int bytes = atoi(argv[2]);
    char buffer[1], *end_ptr;
    clock_t start, end;
    long time_duration;
    FILE *fp;
    long long random_num;
    long long file_size  = strtoll(argv[2], &end_ptr, 10);

    fp = fopen(argv[1], "r");
    start = clock();
    
    while (fread (buffer, 1, 1, fp) == 1){
	random_num = rand() % file_size;	
    }
    
    fclose(fp);
    end = clock();
   
    printf("start: %f\n", (double)start);
    printf("end: %f\n", (double)end); 
    time_duration = (long)(end-start);
    printf("time duration: %lf\n", time_duration);
}
