Brandon Quant
COEN 177L
Lab 1 Documentation

How it works and how you tested it

The Basic Programming Task
The program first reads a command in from the user. If the user types in "exit", which is checked through a string compare in the code, the program will close. If the user types in any other input,the code will first check if fork() is not equal to 0, which means that we are in the parent process; thus we use the waitpid() so that we wait for all the child processes to finish. If the fork() function returns any other value, we use the execve function, which will run the "Hello world", where the Hello World function prints out "Hello World". 

I tested this program by tying in "exit", and the program is then killed. When tying any other word, character, numbers, or syntax(e.g. punctuation), "HelloWorld" is printed


THE SECOND PROGRAMMING TASK
The program first saves the root PID into a variable. Then we print out the root PID so that we know what the root is. Then we run a nested for loop, where the outer for loop runs twice and will check if we are creating the children at the correct node, which in this case is the root node. Then we will check ifthe fork(0 is not equal to 0, which means that we are in the parent process. Thus we then use the waitpid() function to make sure that all the child processes finish. If the fork() function returns any other value, the we run the inner for loop, which will run twice. In the inner for loop, we check if the fork() function is not equal to 0, where we will then use the waitpid() function to wait for those children to finish. If the fork function in the inner loop is equal to any other number, then we use the break statement so that we exit out and stop the program for creating anymore child processes.

Thus for this program, the output is a 3 layered tree where the nodes for the top 2 layers each have 2 children. The inner for loop creates the bottom layer and the outer for loop will create the 2nd layer and the top layer is the originial main function.

I tested the program by using print statements and used the getpid(), which returns the ID of the parent and getppid, which returns the ID of the child. A sample output of the program is:

Root PID: 26565
Child is: 26567 and parent is: 26566
Parent of 26566 is: 26565
Child is: 26568 and parent is: 26566
Parent of 26566 is: 26565
Child is: 26570 and parent is: 26569
Parent of 26569 is: 26565
Child is: 26571 and parent is: 26569
Parent of 26569 is: 26565

This shows that the root PID is 26565, and the children of the root PID are 26566 and 26569. The children of 26566 are 26567 and 26568, and the children of 26569 are 26570 and 26571. 


THE THIRD PROGRAMMING TASK
The program is very similar to the SECOND PROGRAMMING TASK, as since we need 14 children, this would mean that we need another bottom layer. Thus the program will first record the root PID and print it out. Then the for loop will run twice, where the next layer below it, which is 2 nodes. This is accomplished by checking if the fork function is not equal to 0, which means that we are in the parent process; thus we use the waitpid to let all the children processes finish. If the fork functino equals any other number, then we record the new PID, which will be the children of the root. Then we run the for loop again and once again check if the fork() function returns a value that is not 0, then we wait for the children to finish. If the function returns any other value, then we run the last inner for loop, which will follow the same logic as the outer forloop.

Essentially, we are adding one more outer loop so that we get the 4 layered tree where the bottom 3 layers have 2 children each.

I tested the program using print statements and used the getpid(), which retursn the ID of the parent and getppid(), which retursn the Id of th e child. A sample output would be:

Root PID:27765
PID: 27766 and its parent is: 27765
Child is: 27768 and parent is: 27767
Parent of 27767 is: 27766
Child is: 27769 and parent is: 27767
Parent of 27767 is: 27766
Child is: 27771 and parent is: 27770
Parent of 27770 is: 27766
Child is: 27772 and parent is: 27770
Parent of 27770 is: 27766
PID: 27773 and its parent is: 27765
Child is: 27775 and parent is: 27774
Parent of 27774 is: 27773
Child is: 27776 and parent is: 27774
Parent of 27774 is: 27773
Child is: 27778 and parent is: 27777
Parent of 27777 is: 27773
Child is: 27779 and parent is: 27777
Parent of 27777 is: 27773

Thus the root is 27765 and its children are 27766 and 27773. The children of 27766 would be 27767 and 27770. The children of 27767 are 27768 and 27769. The children for 27770 are 27771 and 27772. The children for 27773 would be 27774 and 27777. The children for 27774 are 27775 and 27776. The children of 27777 are 27778 and 27779.


