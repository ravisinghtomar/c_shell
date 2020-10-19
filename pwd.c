#include <stdio.h>
#include <string.h>
#include <unistd.h>


void execute_pwd_func(char *command[200], int len, char command_string[200])
{
    char path[4096] = "\0";
    getcwd(path, 4096);
    printf("%s\n", path);
}