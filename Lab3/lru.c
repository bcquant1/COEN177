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
    int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0;
    int *pageTable = (int *) malloc(sizeof(int)*tableSize);
    char *input = NULL;
    size_t inputAllocated = 0;
    ssize_t bytesRead;
    
    FILE *fp;
    fp = fopen("lru.txt", "w");
        
 
    while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1) {
        pageRequest = atoi(input);
        if(pageRequest == 0) {
            continue;
        }
        numRequest++;
        if(!isInMemory(pageRequest, pageTable, tableSize)) {
            numMisses++;
	    fprintf(fp, "Page %d caused a page fault.\n", pageRequest);
            if(pageTableIndex < tableSize) {
                int i;
		for (i = pageTableIndex; i > 0; i--){
		    pageTable[i] = pageTable[i-1];	        
		}
		pageTable[0] = pageRequest;
		pageTableIndex++;
		//pageTable[pageTableIndex] = pageRequest;
		//pageTableIndex++;
            } else {
                // TODO implement a page replacement algorithm
		int j;
		for (j = tableSize-1; j > 0; j--){
		    pageTable[j] = pageTable[j-1];
		}
		pageTable[0] = pageRequest;
            }
        } // else probably want to update something in pageTable so that lru and second chance work correctly
	else{
	    int k, l, index;
	    for (k = 0; k < tableSize; k++){
		if (pageRequest == pageTable[k]){
		    index = k;
		    break;
		}
	    }
	 
	    for (k = index; k > 0; k--){
		pageTable[k] = pageTable[k-1];
	    }
	    pageTable[0] = pageRequest;
	}
    }
    fprintf(fp,"Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
    printf("Page Faults %d\n", numMisses); 
    fclose(fp); 
    free(input);
    free(pageTable);
    return 0;
}
