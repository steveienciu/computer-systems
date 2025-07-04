/*
 * Consider the following invocation of the program from Problem 10.8:
 * linux> ./p08 3 < foo.txt
 * You might expect that this invocation would fetch and display metadata for file foo.txt. 
 * However, when we run it on our system, it fails with a “bad file descriptor.” Given this behavior, fill
 * in the pseudocode that the shell must be executing between the fork and execve calls
 */

if (Fork() == ) { /* child */
    Dup2(0, 3);
    Execve("p08", argv, envp);
}
