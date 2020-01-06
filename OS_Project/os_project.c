#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fcfs(int *request_list, int request_size){
	int k;
	int total_dist = 0;
	for (k = 0; k < request_size-1; ++k){
		total_dist += abs(request_list[k] - request_list[k+1]); 
	}
	printf("FCFS total distance: %d\n", total_dist);
	return;
}
void scan(int *request_list, int *flags, int request_size, int disk_size){
	int i,j,k,l,m;
	int counter = 1;
	int previous_location = request_list[0];
	int disk_location = request_list[0];
	int starting_location = request_list[0];
	int total_dist = 0;
	printf("Starting disk location: %d\n", disk_location);
	for (i = 0; i < request_size; ++i){
		flags[i] = 0;
	}
	flags[0] = -1;
	for (j = disk_location; j < disk_size; ++j){
		for (k = 0; k < request_size; ++k){
			//printf("Disk location right %d\n", j);
			//printf("request_list[k] %d\n", request_list[k]);
			if (request_list[k] == j){
				if (flags[k] != -1){
					flags[k] = -1;
					counter++;
					total_dist += abs(request_list[k] - previous_location);
					previous_location = request_list[k];
					//printf("Distance going right %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
		if (j == disk_size-1){
			//printf("Previous location: %d\n", previous_location);
			//printf("distance: %d\n",total_dist);
			//printf("disk size: %d\n", disk_size-1); 
			total_dist += abs(previous_location - (disk_size-1));
			previous_location = disk_size-1;
			//printf("Total distance going right %d\n", total_dist);
			break;
		}
	}
	for (l = starting_location; l >= 0; --l){
		for (m = 0; m < request_size; ++m){
			//printf("Disk location left %d\n", l);
			//printf("request_list[m] %d\n", request_list[m]);
			if (request_list[m] == l){
				if (flags[m] != -1){
					flags[m] = -1;
					counter++;
					total_dist += abs(request_list[m] - previous_location);
					previous_location = request_list[m];
					//printf("Distance going left %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
		//printf("counter: %d\n", counter);
		if (l == 0){
			total_dist += previous_location;
			//printf("Total distance going left %d\n", total_dist);
			break;
		}
	}
	printf("SCAN total distance: %d\n", total_dist);
	return;
}
void cscan(int *request_list, int *flags, int request_size, int disk_size){
	int i,j,k,l,m;
	int counter = 1;
	int previous_location = request_list[0];
	int disk_location = request_list[0];
	int starting_location = request_list[0];
	int total_dist = 0;
	printf("Starting disk location: %d\n", disk_location);
	for (i = 0; i < request_size; ++i){
		flags[i] = 0;
	}
	flags[0] = -1;
	for (j = disk_location; j < disk_size; ++j){
		for (k = 0; k < request_size; ++k){
			//printf("Disk location right %d\n", j);
			//printf("request_list[k] %d\n", request_list[k]);
			if (request_list[k] == j){
				if (flags[k] != -1){
					flags[k] = -1;
					counter++;
					total_dist += abs(request_list[k] - previous_location);
					previous_location = request_list[k];
					//printf("Distance going right %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
		if (j == disk_size-1){
			total_dist += abs(previous_location - (disk_size-1));
			//printf("Total distance going right: %d\n", total_dist);
			total_dist += (disk_size-1);
			//printf("Total distance starting from beginning: %d\n", total_dist);
			break;
		}
	}
	previous_location = 0;
	for (l = 0; l < disk_location; ++l){
		for (m = 0; m < request_size; ++m){
			if (request_list[m] == l){
				if (flags[m] != -1){
					flags[m] = -1;
					total_dist += abs(request_list[m] - previous_location);
					previous_location = request_list[m];
					//printf("Distance starting from 0: %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
	}
	printf("CSCAN total distance: %d\n", total_dist);
	return;
}
void clook(int *request_list, int *flags, int request_size, int disk_size){
	int i,j,k,l,m,n;
	int previous_location = request_list[0];
	int disk_location = request_list[0];
	int starting_location = request_list[0];
	int total_dist = 0;
	int max = -1;
	int min = 10000000;
	int counter = 1;
	int index_min = 0;
	printf("Starting disk location: %d\n", disk_location);
	for (i = 0; i < request_size; ++i){
		flags[i] = 0;
	}
	flags[0] = -1;
	for (n = 0; n < request_size; ++n){
		if (request_list[n] > max){
			max = request_list[n];
		}
		if (request_list[n] < min){
			min = request_list[n];
			index_min = n;
		}
	}
	printf("Max request: %d\n", max);
	printf("Min request: %d\n", min);
	
	for (j = disk_location; j <= max; ++j){
		for (k = 0; k < request_size; ++k){
			//printf("Disk location right %d\n", j);
			//printf("request_list[k] %d\n", request_list[k]);
			if (request_list[k] == j){
				if (flags[k] != -1){
					flags[k] = -1;
					counter++;
					total_dist += abs(request_list[k] - previous_location);
					previous_location = request_list[k];
					//printf("Distance going right %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
	}
	total_dist += abs(max - min);
	//printf("DIstance from max to min: %d\n", total_dist);

	counter++;
	flags[index_min] = -1;
	previous_location = request_list[index_min];
	for (l = min; l < starting_location; ++l){
		for (m = 0; m < request_size; ++m){
			//printf("Disk location from min %d\n", l);
			//printf("request_list[k] %d\n", request_list[m]);
			if (request_list[m] == l){
				if (flags[m] != -1){
					flags[m] = -1;
					counter++;
					total_dist += abs(request_list[m] - previous_location);
					previous_location = request_list[m];
					//printf("Distance starting from min: %d\n", total_dist);
				}
			}
		}
		if (counter == request_size){
			break;
		}
	}
	printf("CLOOK total distance: %d\n", total_dist);
	return;
}
int main(int argc, char*argv[]){
	//argv[1] = disk size, argv[2] = request_size
	if (argc < 3){
		printf("Not enough arguments\n");
		return -1;
	}
	int disk_size, request_size;
	disk_size = atoi(argv[1]);
	request_size = atoi(argv[2]);
	printf("Disk size: %d\n", disk_size);
	printf("Request size: %d\n", request_size);

	int *request_list = (int*) malloc(sizeof(int)*request_size);
	int *flags = (int*) malloc(sizeof(int)*request_size);

	srand(time(0));
	int i,j;
	for (i = 0; i < request_size; ++i){
		request_list[i] = rand() % disk_size;		
		flags[i] = 0;
	}
	for (j = 0; j < request_size; ++j){
		printf("%d, ", request_list[j]);  
	}
	printf("\n");
	fcfs(request_list, request_size);
	scan(request_list, flags, request_size, disk_size);
	cscan(request_list, flags, request_size, disk_size);
	clook(request_list, flags, request_size, disk_size);
	free(request_list);
}


