#include "header.h"
#include "input.h"

struct passwd get_user_name()
{
    uid_t uid = geteuid();
    struct passwd *passw = getpwuid(uid);
    return *passw;
}

int check_tilda(char *str1, char *str2, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    child_process = 0;
    strcpy(prev_dir, "\0");
    struct utsname s;
    struct passwd s1;
    char command[3000] = "\0";
    strcpy(com_str, "\0");
    char usr[200] = "\0";
    char sys_name[200] = "\0";
    char cw_d[4096] = "/home/";
    char pw_d[4096] = "~";
    s1 = get_user_name();
    strcpy(usr, s1.pw_name);
    uname(&s);
    strcpy(sys_name, s.nodename);
    strcat(cw_d, usr);
    int length = strlen(usr) + strlen("/home/");
    char str1[length];
    strcpy(str1, cw_d);
    int temp = chdir(cw_d);
    if (temp < 0)
    {
        printf("Error\n");
    }
    strcpy(prev_dir, cw_d);
    if (temp < 0)
    {
        bold_red();
        printf("Error : ");
        reset();
        printf("Failed to change directory to ~\n");
        return 0;
    }
    while (1)
    {
        check_process();
        getcwd(cw_d, 4096);
        if (check_tilda(str1, cw_d, length))
        {
            for (int i = 0; i < strlen(cw_d); i++)
            {
                pw_d[i + 1] = cw_d[length + i];
            }
            printf("<%s@%s:%s>", usr, sys_name, pw_d);
        }
        else
        {
            printf("<%s@%s:%s>", usr, sys_name, cw_d);
        }
        if (fgets(command, sizeof command, stdin))
        {
            command[strcspn(command, "\n")] = 0;
            strcpy(com_str, command);
	    if(strcmp(com_str," ")||strcmp(com_str,"  ")||strcmp(com_str,"   ")){
            	create_history(command);
	    }
            if (!strcmp(command, "clear") || !strcmp(command, "c"))
                printf("\e[1;1H\e[2J");
            else if (!strcmp(command, "exit") || !strcmp(command, "quit"))
                break;
            else
                dist_command_1(command);
        }
        else
        {
            printf("Error : In reading the command, Please Enter the command again\n");
        }
    }
    return 0;
}
