// variables --

pid_t array[200];
char com_str[200];
int child_process;
int back_len ;
char prev_dir[5000];

//color funcions --

void bold_green();
void bold_blue();
void bold_red();
void bold_yellow();
void yellow();
void red();
void green();
void blue();
void green();
void reset();

//functions : --

//main functions : --

struct passwd get_user_name(); 

int check_tilda(char *str1, char *str2, int len);

//pwd function : --

void execute_pwd_func(char *command[200], int len, char command_string[200]);

//cd function : --

void execute_cd_func(char *command[200], int len, char command_string[200]);

//echo function : --

void execute_echo_func(char *command[200], int len, char command_string[200]);

// ls functions : --

void print_time(char *str);

void implement_ls(DIR *dr, int flag, char directory[200], char command_string[200]);

void execute_ls_func(char *command[200], int len, char command_string[200]);

// pinfo function : --

void execute_pinfo_func(char *command[200], int len, char command_string[200]);

//history functions : --

void restructure_history(int len, char path[500], char *buffer[200]);

int check_history(char *command);

void create_history(char *command);

void print_history(char *command[200], int len, char command_string[200]);

//nightswatch functions : --

void mode1();

void mode2();

int getkey();

int get_interrupt(int flag);

int get_newborn();

void nightswatch(char *command[200], int len, char command_string[200]);

//check process function : --

void check_process();

//back-front process functions : --

void execute_back_process(char *command[200], int len, char command_string[200]);

void execute_front_process(char *command[200], int len, char command_string[200]);

//command handle functions : --

void dirct_command(char *str[200], int len, char command_string[200]);

int dist_command_2(char *command);

void dist_command_1(char *command);