#include "header.h"
#include "input.h"

void check_process()
{
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    if (pid > 0)
    {
        child_process--;
        if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
        {
            green();
            printf("Process %d exited Successfully\n", pid);
            reset();
        }
        else if (WIFSIGNALED(status))
        {
            red();
            printf("Process %d exited abnormally\n", pid);
            reset();
        }
    }
}