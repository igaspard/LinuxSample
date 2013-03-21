#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*  Spawn a child process running a new program.  PROGRAM is the name
    of the program to run; the path will be searched for this program.

    The exec family function which contain letter 'l' accept C args.

    contain 'p' accept ARG_LIST is a NULL-terminated list of character 
    strings to be passed as the program's argument list.  
    
    Returns the process id of the spawned process.  */

int spawn_argv(char *program, const char **argv_list)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        printf("%s Process forked\n", __func__);
        execlp(program, *argv_list, NULL);
        fprintf(stderr, "Error occured execlp()\n");
        abort();
    }
    else {
        return child_pid;
    }
}

int spawn_arg(char *program, char **arg_list)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == 0) {
        printf("%s Process forked\n", __func__);
        execvp(program, arg_list);
        //The execvp function returns only if an error occurs.
        fprintf(stderr, "Error occured execvp()\n");
        abort();
    }
    else {
        return child_pid; 
    }
}

int main(int argc, const char *argv[])
{
    char *arg_list[] = {
        "ls",
        "-t",
        "/",
        NULL    /* The argument list must end with a NULL.  */
    };

    printf("This is %s program\n", __func__);

    spawn_argv("ls", argv);
    spawn_arg("ls", arg_list);

    printf("%s program done\n", __func__);
    return 0;
}
