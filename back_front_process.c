#include "header.h"
#include "input.h"

void execute_back_process(char *command[200], int len, char command_string[200])
{
    command[len - 1] = NULL;
    pid_t pid;
    child_process++;
    pid = fork();
    if (pid == 0)
    {
        int val = execvp(command[0], command);
        if (val == -1)
        {
            bold_red();
            printf("\nError : ");
            reset();
            printf("Failed to execute command \n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else if (pid < 0)
    {
        child_process--;
        bold_red();
        printf("Error : ");
        reset();
        printf("Failed to fork \n");
    }
    else
    {
        printf("[%d] %d\n", child_process, pid);
    }
    return;
}
void execute_front_process(char *command[200], int len, char command_string[200])
{
    command[len] = NULL;
    int val;
    int status;
    pid_t pid = fork();
    if (pid < 0)
    {
        bold_red();
        printf("Error : ");
        reset();
        printf("Failed to fork\n");
        return;
    }
    else if (pid == 0)
    {
        val = execvp(command[0], command);
        if (val == -1)
        {
            bold_red();
            printf("Error : ");
            reset();
            printf("Failed to execute the command \n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        val = waitpid(pid, &status, 0);
        if (val < 0)
        {
            bold_red();
            printf("Error : ");
            reset();
            printf("Failed to wait for the child[ %d ] to complete\n", pid);
        }
    }
}
