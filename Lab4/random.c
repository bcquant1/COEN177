#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
    char buffer[1], *end_ptr;
    long long bytes = strtoll(argv[2], &end_ptr, 10);
    long long file_size = strtoll(argv[3], &end_ptr, 10);
    clock_t start, end;
    long time_duration;
    FILE *fp;
    long long counter = 0;
    long long random_num;
    
    fp = fopen(argv[1], "r");
    
    start = clock();
    random_num = rand() % file_size;
    printf("%d\n", random_num);	
    fseek(fp, random_num, SEEK_SET);
 
    while (fread (buffer, 1, 1, fp) == 1){
	random_num = rand() % file_size;
	fseek(fp, random_num, SEEK_SET);
	counter++;
	if (counter > bytes){
	    break;
	}
    }
    
    fclose(fp);
    end = clock();
   
    printf("start: %f\n", (double)start);
    printf("end: %f\n", (double)end); 
    time_duration = (long)(end - start);
    printf("%f\n", time_duration);
}
