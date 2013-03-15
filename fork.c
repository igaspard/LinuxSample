#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    pid_t child_pid;
    printf("The main program process ID is %d\n", (int) getpid());

    child_pid = fork();

    if (child_pid != 0) {
        printf("This is parent process, with id %d\n", (int) getpid());
        printf("The child's process ID is %d, return value from fork()\n", (int) child_pid);
    }
    else {
        printf("This is the child process, with id %d\n", (int) getpid());
        printf("The return vaule from fork(): %d\n", (int) child_pid);
    }
    return 0;
}
