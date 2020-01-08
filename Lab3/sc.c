#include <stdio.h>
#include <stdlib.h>

int parseArguments(int argc, char *argv[]) {
    int tableSize;
    if(argc == 2 && (tableSize = atoi(argv[1]))) {
        return tableSize;
    }
    fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
    exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize) {
    int i;
    for(i = 0; i < tableSize; i++) {
        if(pageRequest == pageTable[i]) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int tableSize = parseArguments(argc, argv);    
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0, numPages;
    int *pageTable = (int *) malloc(sizeof(int)*tableSize);
    int *reference = (int *) malloc(sizeof(int)*tableSize);
    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
    
    FILE *fp;
    fp = fopen("sc.txt", "w");
 
    while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
        pageRequest = atoi(input);
        if(pageRequest == 0) {
            continue;
        }
        numRequest++;
        if(!isInMemory(pageRequest, pageTable, tableSize)) {
            //printf("Page %d caused a page fault.\n", pageRequest);
            numMisses++;
	    fprintf(fp, "Page %d caused a page fault.\n", pageRequest);
            if(numPages < tableSize-1) {
		numPages++;
                pageTable[pageTableIndex] = pageRequest;
		reference[pageTableIndex] = 0;
		pageTableIndex = (pageTableIndex+1)%tableSize;
	    } 
	    else {
                // TODO implement a page replacement algorithm
		while (reference[pageTableIndex] == 1){
		    reference[pageTableIndex] = 0;
		    pageTableIndex = (pageTableIndex+1)%tableSize;
		}
		pageTable[pageTableIndex] = pageRequest;
		reference[pageTableIndex] = 0;
		pageTableIndex = (pageTableIndex+1)%tableSize;
            }
        } 
	else{
	    int j;
	    for (j = 0; j < tableSize; j++){
		if (pageRequest == pageTable[j]){
		    reference[j] = 1;
		    break;
		}
	    }
	}
    }
    fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Page Faults: %d\n", numMisses);
    fclose(fp); 
    free(input);
    free(pageTable);
    return 0;
}
