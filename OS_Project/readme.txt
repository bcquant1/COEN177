Brandon Quant
OS Lab 5

In this lab, I explored the total distance for different disk replacement algorithms. Using a random sequence of requests, I measured the total distance for the algorithms of First Come First Serve, SCAN, CSCAN, and CLOOK. I started at the first request to start at a random location in the disk. I take in the request list size and the disk size as parameters from the command line. 

For the First Come First Serve algorithm, given the the sequence of requests stored in array, I ran through the array and calculated the distance between each of the requests and got the sum of all those requests, which is the total distance.

For the SCAN algorithm, I used a request list and a flags list to keep track of the requests that have already been completed. The starting location is the first entry in the request list. The first for loop runs from the first request, which is a value in the disk to the end of the disk. The inner for loop runs through the entire request array and checks each request with the range of the disk numbers. If there is a match, then we know that there is a request at that disk value, thus we set the flag, increment the counter, and calculate the distance from that match to the previous request. Then we add that value to the total_dist and set the previous_location to the request. Then I will checkto see if the counter is equal to the request_size, which checks the case if the starting request is the smallest request and so that we don't run the next if statement. If the if statement is true, then we break out of the loop since we don't need to check for matches anymore. The next if statement is because the SCAN algorithm will go to the end of the disk, where if we reach the end of the disk, then we need to add that distance to the total distance and set the previous location. Next, we run from the starting location, which is the first request, until we reach 0. This is when we are moving to the left. The inner loop is to check all the requests to see if we have a match. If we do, then we set the flags, increment the counter, and add the distance from the previous location to the matched request to the total distance. We also check if the counter is equal to the request_size so that if we finish all the requests, we won't check the next if statement. The next if statement is when we reach the start of the disk, where we will add that distance to the total distance.

For the CSCAN algorithm, the difference would be that once we reach the end of the disk, we will go back to the start of the list and keep moving the same direction as previously, where we don't check any requests when going back to the end of the list. To do this, we run the 2 for loops, one from the starting request to the end of the disk, and the inner for loop which checks the whole request array. We will then check the matches, which is the same as the SCAN algorithm. We then check if the counter equals the request_size. The difference is when we reach the end of the disk. This is where we add the distance to the end of the disk but also the distance of the total disk, because we are going back to the very end. Outside the for loop, we change the previous_location to 0 because we have gone back to the start of the disk. Then we run the 2 nested for loops, one from 0 to the starting request, and the innder for the whole request array. We will then check for matches again, and if we find a match, we will add that distance to the match to the total distance. We also check if the counter equals the request_size in the outer for loop to check if we have gone through all the requests.

For the CLOOK algorithm, the difference would be that we don't need to go to the ends of the disk, but rather only until the max and the min of the requests on the disk. Thus the change to the algorithm compared to CSCAN would be that we first calculate the max and the min of the request list and the outer for loops will only run from the starting request to the max location and from the minimum request to the starting location.


A sample output for the 4 algorithms with a disk size of 200 and a request array size of 30 would be:
Disk size: 200
Request size: 30
85, 130, 132, 112, 108, 3, 77, 66, 9, 53, 133, 185, 105, 76, 156, 4, 56, 6, 186, 103, 155, 112, 134, 55, 1, 77, 16, 90, 179, 104, 
FCFS total distance: 1825
SCAN total distance: 312
CSCAN total distance: 390
Starting disk location: 85
Max request: 186
Min request: 1
CLOOK total distance: 362

The FCFS distance is the greatest, because it only takes in inputs as they come in, thus does not have any optimization for the distance between the requests where we may end up going back and forth in both directions on the disk in this algorithm.

The CSCAN distance would be the next greatest because we have to include the additional distance of going from the end of the disk to the start of the disk. And as the disk size grows, we will have a greater distance that we have to add the total distance.

The CLOOK distance would be the next greatest because it is very similar to the CSCAN, but it does not have the additional distance of travelling to the ends of the disk, and only travels to the max and min of the requests on the disk. However, with a large enough request array where the min and the max are the ends of the disk, or if the randomly generated requests happen to include the min and max of the disk as requests, the distance for CLOOK would be the same as that of the CSCAN algorithm.

The SCAN distance was the smallest, because it doesn't include the distance of the disk size but it does not give as much fairness to requests as the CSCAN and CLOOK algorithms do.

From the graphs, the First Come First Serve Algorithm performs the worst since there is no optimization for efficiency. For the other algorithms of SCAN, CSAN and CLOOK, the distances remained around the same when increasing either request size or disk size. However, CSCAN would perform the worse than SCAN and CLOOK because of the extra distance to get back to the beginning of the disk but does give more fairness to requests. SCAN would be better than CSCAN and CLOOK because it does not have the extra distance that the other 2 algorithms have. CLOOK on average would perform better than CSCAN; the only case where they are the same would be when the minimum and maximum requests were the ends of the disk.


