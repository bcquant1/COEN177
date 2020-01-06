Brandon Quant
Lab 3
ReadMe


FIFO
I implemented the FIFO page replacement algorithm using a queue. This was done by inserting page requests at the back of the queue where the head of the queue would hold the oldest entry. If we have a miss and the page table is not full, then we insert the entry at the back of the array and increment the pageTableIndex and the numRequest. If we have a miss and the pageTable is full, then we shift everything to the left one entry. This will remove the head of the queue, which was the oldest entry and will give us room to add the new PageRequest at the end of the array.


LRU
For this implementation, I used an array where the entries are inserted at the front of the array and the oldest entry would be at the back fo the array. If we had a miss and the pageTable is not full, then we would shift all the entries 1 entry to the right, thus the oldest entry, which would be at the end of the array, would be taken out and we would have space at the beginning of the array to put in the new pageRequest. If we had a miss and the pageTable is full, we would also shift all the entries 1 entry to the right and place the new pageRequest at the head of the queue. If we had a hit, then we would take that pageRequest and and place it at the front of the array since it had just been accessed. We do this by running through the array and seeing if the pageRequest is the same as an entry in the pageTable. If it is we would record the index and starting from that index to the beginning of the array, we would shift all the entries 1 entry to the right and place that entry that has just been accessed at the front of the array.

Second Chance
For this implementation, I used a circular array. If we got a miss and the number of pageRequests is less than the tableSize-1, then we would insert the new pageRequest into the pageTable at pageTableIndex and add a new entry at the same pageTableIndex, where the reference bit would be initially set to 0. Then we would update the pageTableIndex so that it will wrap back around to the front of the array if needed. If we have a miss and the pageTable is full, then we would run through the circular array and find the oldest entry that has a reference bit of 0. When running through the array and when we pass entries that have a reference bit of 1, we will reset their reference bit back to 0 since they have been given their second chance. Once the oldest entry with reference bit 0 is found, we will insert the new pageRequest and reference entry, which is set to 0, at that pageTableIndex and then increment the pageTableIndex and mod it with the tableSize, which will allow us to go back to the beginning of the array. If we have a hit, we would just set the reference bit to 1. This is done by running through the array and if the pageRequest is equal to an entry in the pageTable, then we set its reference bit to 1. 

FIFO Test Results:
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 10
Hit rate = 0.306953
Page faults = 3867230
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 50
Hit rate = 0.486111
Page faults = 2867520
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 75
Hit rate = 0.536044
Page faults = 2588892
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 100
Hit rate = 0.570789
Page faults = 2395013
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 150
Hit rate = 0.622332
Page faults = 2107404
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 200
Hit rate = 0.664779
Page faults = 1870547
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 250
Hit rate = 0.703559
Page faults = 1654152
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 300
Hit rate = 0.738997
Page faults = 1456407
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 350
Hit rate = 0.774776
Page faults = 1256760
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 400
Hit rate = 0.817780
Page faults = 1016796
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 450
Hit rate = 0.860574
Page faults = 778005
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 500
Hit rate = 0.902122
Page faults = 546166
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 100
Hit rate = 0.570789
Page faults = 2395013


LRU Test Results:
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 10
Hit rate = 0.310150
Page Faults 3849391
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 50
Hit rate = 0.513629
Page Faults 2713970
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 75
Hit rate = 0.563751
Page Faults 2434287
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 100
Hit rate = 0.597564
Page Faults 2245610
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 150
Hit rate = 0.646351
Page Faults 1973378
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 200
Hit rate = 0.684209
Page Faults 1762125
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 250
Hit rate = 0.720091
Page Faults 1561906
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 300
Hit rate = 0.753123
Page Faults 1377585
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 350
Hit rate = 0.784399
Page Faults 1203064
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 400
Hit rate = 0.815174
Page Faults 1031336
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 450
Hit rate = 0.845574
Page Faults 861704
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 500
Hit rate = 0.901282
Page Faults 550849

Second Chance Results:
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 10
Hit rate = 0.312724
Page Faults: 3835030
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 50
Hit rate = 0.486111
Page Faults: 2867520
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 75
Hit rate = 0.536044
Page Faults: 2588892
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 100
Hit rate = 0.599303
Page Faults: 2235907
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 150
Hit rate = 0.622332
Page Faults: 2107404
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 200
Hit rate = 0.664779
Page Faults: 1870547
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 250
Hit rate = 0.703559
Page Faults: 1654152
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 300
Hit rate = 0.738997
Page Faults: 1456407
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 350
Hit rate = 0.774776
Page Faults: 1256760
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 400
Hit rate = 0.814958
Page Faults: 1032544
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 450
Hit rate = 0.860574
Page Faults: 778005
[bquant@linux11118 lab3]$ cat accesses.txt | ./a.out 500
Hit rate = 0.901990
Page Faults: 546902

To test the algorithms, I ran each algorithm against the sample input of 100 and compared it with the sample output files and checked that both of the files are the same.
