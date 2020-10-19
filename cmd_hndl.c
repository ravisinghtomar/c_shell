#include "header.h"
#include "input.h"

void dirct_command(char *str[200], int len, char command_string[200])
{
    if (!strcmp(str[len - 1], "&"))
    {
        execute_back_process(str, len, command_string);
    }
    else if (!strcmp(str[0], "cd"))
    {
        execute_cd_func(str, len, command_string);
    }
    else if (!strcmp(str[0], "pwd"))
    {
        execute_pwd_func(str, len, command_string);
    }
    else if (!strcmp(str[0], "echo"))
    {
        execute_echo_func(str, len, command_string);
    }
    else if (!strcmp(str[0], "ls"))
    {
        execute_ls_func(str, len, command_string);
    }
    else if (!strcmp(str[0], "pinfo"))
    {
        execute_pinfo_func(str, len, command_string);
    }
    else if (!strcmp(str[0], "history"))
    {
        print_history(str, len, command_string);
    }
    else if (!strcmp(str[0], "nightswatch"))
    {
        nightswatch(str, len, command_string);
    }
    else
    {
        execute_front_process(str, len, command_string);
    }
}
int dist_command_2(char *command)
{
    int flag_com = 0;
    char command_string[200] = "\0";
    strcpy(command_string, command);
    char *str[200];
    int i = 0;
    char *token = strtok(command, "\t \n");
    while (token != NULL)
    {
        flag_com = 1;
        str[i] = token;
        i++;
        token = strtok(NULL, "\t \n");
    }
    if(flag_com)
    {
        dirct_command(str, i, command_string);
    }
    free(token);
    return 1;
}
void dist_command_1(char *command)
{
    int val;
    char temp[200] = "\0";
    char *token = strtok(command, ";");
    while (token != NULL)
    {
        strcpy(temp, token);
        token = strtok(NULL, ";");
        if (strcmp(temp, ""))
        {
            val = dist_command_2(temp);
            if (!val)
                return;
        }
    }
    free(token);
}
