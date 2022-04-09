## main.h
we will find all te prototypes of functions that we will use later on.

##Loop
In this file we will start the arguments, the line to read and the status.
in a prototype void.
We will give an input for the user to type a command and match the line, the arguments and the status to its functions that we will use later.
Finally we release the line and arguments as ling as the status exists.

##Readline
In an function that read your command, we use getline to read the line as long as it is equeal to the buffer we have set to set and we are at the end of the two.
If this happens, the function is correct and we get the end of the.
Otherwise we will get an error.

##Tokenline
We parse the line bi splitting the incoming arguments, so we will use separators to differentiate when it is another argument.
In this way, we will tokenize using spaces as a form of separator.
We tokenisze with the help of strtok, our line based on the delimiter(our space), if our token is not empty.
On the other hand we will find that i the buffer is less than the traversed position(we are out of memory), in the latter case, we will reallocate memory for our already split tokens.
If the tokens are empty, we will get an error.
As long as everything works we will end our pointer array terminated in null.

##Shell
We take the argument list by forking the process and saving the return value.
Once the fork is created, we have two processes running simultaneously.
Throug execve we execute the child process,(execve is a variant of exec).
Execve, executes a program referenced by the pathname, and runs a new program, replacing the previous one.
It does not need o return in case of success.
If the program returns something it breaks taking into account its base condition.
In case everything works, we must make the father wait with wait pid until the child process dies, but we must use macros to make sure with totaly that the child porocess relly dies.
Finally we return 1 to request a new entry.

##Buildint
We list commands with their corresponding function
#exit
We create the exit function to implement ir, returning 0 as a signal to end the loop.
