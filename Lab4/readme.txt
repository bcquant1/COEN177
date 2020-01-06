Brandon Quant
COEN 177 Lab 4
ReadMe

To create the files of specific sizes, I used the head command:

Head -c 5GB /dev/zero > 5gb.txt // this creates a file filled with zeros called 5gb.txt with a file size of 5GB

Thus the filename and the file size can be changed accordingly. I then created 5 files of size 10mb, 100mb, 500mb, 1gb and 5gb.

For the sequential pattern, I first take in the filename and file size as arguments from the command line. Then I open the 
file, read through the entire file and then record the clock cycles that it takes. When running through the file, I calculated 
the random number in order to match the overhead when doing the random search. I then ran through the files of different sizes 
and recorded the clock cycles for each file.  

For the random pattern, I take in the filename, the number of bytes, and the file size as arguments from the command line. 
I first will start at a random location by first generating a random number and then using fseek to go to that location. 
Then I will run through the file and will go to a random location by calculating a random number each time and then 
using fseek. Then I keep a counter and once I reach the amount of bytes that I need, which is the file size, I stop reading 
from the file and record the clock cycles.

Consistenly, the sequential search performs better. As the file sizes increase, for sequential pattern, the graph for the 
clock cycles is a linear growth. For the random pattern, as the file sizes increases, the graph for the clock cycles is an 
exponential growth.    

