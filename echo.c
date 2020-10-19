#include <stdio.h>

void execute_echo_func(char *command[200], int len, char command_string[200])
{
    for (int i = 1; i < len; i++)
    {
        printf("%s ", command[i]);
    }
    printf("\n");
}