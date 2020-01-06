Brandon Quant
Lab 2 README

MINIX DESCRIPTION:

MINIX is a round robin scheduler that has 16 available queues. MINIX is initialized by the reincarnation server and init processes, which total to 7 essential processes. Additionally, the kernel will always pick the process at the head of the priority queue and in the original scheduling algorithm, the kernel will check if the head is empty, and if it is, to move on to the next queue. MINIX has 16 available queues, which is set in the .h file and queue 0 has the highest priority while queue 15 has the lowest priority.   

PART 1: BANNER CHANGE

I had first navigated to the /usr/src/kernel directory since the kernel code was in the source files of the system resources, which is similar to the file hierarchy of Linux. Then I found the file that the text was located by using the command grep. The steps with code I took are:

grep -n Amsterdam *
1) Grep is the command to print the lines that match the text
2) -n prints out the line number and file name
3) Amesterdam was chosen since it was in the banner when loading Minix the first time
The output was then in main.c and on line 275

Then I looked through file and changed the print statement to my name so that it would appear in the banner the next time Minix is rebooted.

To test this, I used "make world" when in /usr/src/ to compile the OS. Then I used "reboot" to restart Minix and then was able to see my name in the banner


PART 2: RANDOMIZED PROCESS SCHEDULING ALGORITHM

The second part of this lab was modifying the process scheduling algorithm for Minix. WHen reading up on the manual for Minix, I found that queues 0-6 are system queues thus should not be touched for randomizing the processes. Thus in order to randomize the processes, we randomize the selection of queues

The file that I edited was proc.c and specifically, the function I edited was pick_proc (which stood for pick processes).The code that I added within the for loop is:
if (q > 6){
    q = rand() % 9 + 7;
}

The reasoning behind the code as that if the process is greater than 6, which meant that it is not one of the critical processes, then we can choose a random queue by using the rand function. rand() % 9 would give us a range from 0 to 8, and by adding 7, the range would then be 7-15, which is the range of queues that we can randomize. 

To test this, I ran "make world" in /usr/src to compile the OS again. Then I used "reboot" to ensure that the OS was still working. But now, the OS runs at a much slower rate because it has a less efficient algorithm. Instead of running through each queue one by one, it would now choose less prioritized queues at random, thus is the reason that the OS became slower. 
