#include <stdio.h>

void execute_echo_func(char *command[200], int len, char command_string[200])
{
    for (int i = 1; i < len; i++)
    {
        printf("%s ", command[i]);
    }
    printf("\n");
    
    ///// Implementation End here   ------ 


    ///// Below with more functionality of echo but removed after recieved mail about echo
    /* 
    if (!strcmp(command[1], "-n"))
    {
        int i = 0;
        for (i = 0; i < strlen(com_str); i++)
        {
            if ((com_str[i] == '-') && (com_str[i + 1] == 'n'))
            {
                i += 2;
                break;
            }
        }
        for (; i < strlen(com_str); i++)
        {
            printf("%c", com_str[i]);
        }
    }
    else
    {
        int i = 0;
        for (i = 0; i < strlen(com_str); i++)
        {
            if ((com_str[i] == 'e') && (com_str[i + 1] == 'c'))
            {
                i += 5;
                break;
            }
        }
        for (; i < strlen(com_str); i++)
        {
            printf("%c", com_str[i]);
        }
        printf("\n");
    } */ 
}
