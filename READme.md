Assignment#2
--- Shell Part # 2

Creat Executable : make shell
Execute          : ./shell

Exiting :- 1) "quit"
           2) "exit"
           3) CNTR + D


Requirements :-


.h files :-
    1)header.h  *contains all modules*
    2)input.h   *contains names of function and global variables*


Files :-
    1)Main.c

1)Shell Prompt <user@sys_name :*absolute address*>, shell open invoked with */home/user* as initial address.
2)"~" or (/home/user) are treated as same any address with as substring */home/user* is replaced with *~*,
3)color are not used for the prompt.
4)signal functions are also present in this file.

### For assignment # 2 :

**Specification 1: Display requirement** :-

Files :-
    1)Main.c

1)Shell Prompt <user@sys_name :*absolute address*>, shell open invoked with */home/user* as initial address.
2)"~" or (/home/user) are treated as same any address with as substring */home/user* is replaced with *~*,
3)color are not used for the prompt.

**Specification 2: Builtin commands** :-

Files :-
    1)cd.c          *cd function implemented here*
    2)pwd.c         *pwd function implemented here*
    3)echo.c        *echo function implemented here*

1)cd -> 
        -- Some Examples of working commmands -
        a) cd .                             a) *Stays in the current directory*
        b) cd ..                            b) *Moves to the parent directory*
        c) cd ~                             c) *Moves to /home/user/*
        d) cd ~/                            d) *Same as cd ~*
        e) cd ~/<path>                      e) *Moves to the path if exists*
        f) cd ~/<direrctory>/               f) *Same as cd ~/<directory>*
        g) cd <absolute_path_from_root>     g) *Moves to path address is exists*
        h) cd <absolute_path_from_root>/    h) *Same as cd <absolute_path_from_root>*
        i) cd <rltv_path_from_cur_dir>      i) *Moves to path address is exists*
        j) cd <rltv_path_from_cur_dir>/     j) *Same as cd <rltv_path_from_cur_dir>*

        Errors : if directory not present or if chdir Failed to execute.

2)pwd ->
        prints present working working directory
        getcwd used to get path of directory
        prints absolute path from root like bash Shell.

3)echo ->
        printf everything written in front of echo (except for ";" is used in the string)
        All \t or "<space>^n" are replaced by simple <space> like in bash Shell.

**Specification 3: ls command** :-

Files :-
    1)ls.c          *ls function implemented here* 

1)ls ->
        *if n==0  *Default directory is "."*
        *Directory Path should be relative or absolute it can also be ".", "..", "~".* 
        *"~/" is not implemented it will give error.*
        *"~/<directory>" will not work.*
        *"/home/user/Desktop" will work.* 
        -- Some Examples of working commmands -
        a) ls <directory>^n                 a) *output:*            
                                                    *Directory(1) : all visible files & directories*
                                                    *Directory(2) : all visible files & directories*
                                                    *.                                             *
                                                    *.                                             *
                                                    *Directory(n) : all visible files & directories*
                                                    //*Directory(1 to n):* in yellow color
        b) ls -l^n <directory>^n            b) *output:*            
                                                    *Directory(1) : all visible files & directories with respective details*
                                                    *Directory(2) : all visible files & directories with respective details*
                                                    *.                                             *
                                                    *.                                             *
                                                    *Directory(n) : all visible files & directories with respective details*
                                                    *Total : (int)total block sizes of 1024*
                                                    //*Directory(1 to n):* in yellow color
        c) ls -a^n <directory>^n            c) *Same as ls <directory>^n, but will also show hidden files & directories*
        d) ls -al^n <directory>^n           d) *Same as ls -l^n <directory>^n, but will also show hidden files & directories*
        e) ls -l^n -a^n <directory>^n       e) *Same as ls -al^n <directory>^n

        Error : If directory not found or wrong path or used "~" in absolute path.


**Specification 4: System commands with and without arguments** :-

Files :-
    1)back_front_process.c    *Both front and back process function implemented here*

Implemted foreground and background process functionality present
Incase : prompt does not appear press "Enter" in background process implementation.
         Commands like vi &/getdit & may open respective applications. 

**Specification 5: pinfo command (user defined)**

Files :-
    1)pinfo.c          *pinfo function implemented here*

1)pinfo ->
        a) If no id given then id of Shell is treated as id value.
        b) Getpid() is used to find pid of the Shell.
        c) Used */proc/<pid>/stat* for getting virtual memeory & State of Process.
        d) Used */proc/<pid>/exe* for getting the executable path.
        e) If executable path not present then its description is printed from */proc/<pid>/stat* file.

        Error : If process doesnot exist or If failed to open/read required files or wrong input is given.

**Specification 6: Finished Background Processes** :-

Files :-
    1)check_process.c       *Function implemented here*

1)check_process ->
        a) Printed whether process terminalted successfully(green color) or abnomally(red color).
        b) Used Flags for above.


### For assingment # 3 :

**Specification 1:  Input/Output Redirection** :-

Files :-
    1)redirect_handle.c      *contains implementation of ">","<",">>" commands*

Details :-
        ●Error message is displayed if the input file does not exist.
        ●The output file is created (with permissions ​0644​) if it does not already exist.
        ●In case the output file already exists, it is overwritten in case of ">"​ and appended to in case of "​>>"​.
        ●exit code true if command runs smoothly else false.

**Specification 2: Command Pipelines**

Files :-
    1)pipe_handle.c         *contains implementation of pipeline commands*

Details :-
        ●One or more commands can be piped.
        ●supports any number of pipes.
        ●Errors are handled.
        ●Exit codes as per last command executed.

**Specification 3: I/O Redirection within Command Pipelines**

Files :-
    1)pipe_handle.c         *contains implementation of pipeline commands*
    2)redirect_handle.c     *contains implementation of ">","<",">>" commands*

Details :-
        ●One or more commands can be piped.
        ●supports any number of pipes.
        ●Errors are handled as per both pipes and redirection.
        ●Exit codes as per last command executed.

**Specification 4: User-defined Commands**

Files :-
    1)jobs_handle.c                 *contains implementation of "jobs","kjobs","overkill","fg","bg" commands*
    2)environ_handle.c              *contains implementation of "setenv","unsetenv" commands*
    3)main.c                        *contains implementation of quit*

Details :-

    setenv :-
        ●Sets environment variable.
        ●Syntax error if syntax is not like its descrived in the pdf.
        ●Can not set "" as environment variable.
        ●exit code true if command runs successfully

    unsetenv :-
        ●unsets environment variable if present.
        ●Syntax error if syntax is not like its descrived in the pdf.
        ●Error if environment variable not present.
        ●exit code true if command runs successfully
         

    jobs :-
        ●jobs + any_thing_else will give *error*.
        ●gives all the running/stopped job using smallest unused number as their index which returns to 1 after use of overkill.  
        ●Exit codes true if no internal error occurs during command implementation.

    kjob :-
        ●any difference in said syntax and given syntax will result in error.
        ●Error if job index not present or sygnal num is not defined.
        ●exit code true if command runs successfully.
    
    fg :-
        ●any difference in said syntax and given syntax will result in error.
        ●Error if no such process with index number ever created.
        ●exit code as descrived in pdf.

    bg :-
        ●any difference in said syntax and given syntax will result in error.
        ●Error if no such process with index number ever created.
        ●exit code as descrived in pdf.

    overkill :-
        ●overkill + any_thing_else will give *error*.
        ●kill all the background command.
        ●Exit codes true if no internal error occurs during command implementation.
        ●No error if no backgraound process is present.

    quit :-
        ●Uses feof() function to know whether cntl + D is pressed or not.
        ●Treated as a sygnal not as a command.

**Specification 5: Signal Handling**

    CTRL-Z :-
        ●pushes any currently running foreground job into the background.
        ●change its state from running to stopped.

    CTRL-C :-
        ●interrupt any currently running foreground job.
        ●No effect on the terminal.

**Bonuses**

Files :-
    1)cd.c                          *contains implementation of cd- along with cd*     
    2)main.c                        *contains printing part of Bonus 2*
    3)bonus3_handle                 *contains implementation of Bonus 3*
    4)history.c                     *contains implementation of history*
    5)nightswatch.c                 *contains implementation of nightwatch command*

### For assignment # 2 :

    Bonus 1 :-
        a) implementation in cd-.
        b) By storing previous directory and chdir function.

    Bonus 2 :-
        a)   :') if exit code 1.
        b)   :'( if exit code 0.

    Bonus 3 :-
        a) refer bonus3_handle.c file

### for assignment # 3 :

1)history :-
        a) History stored in */home/user/.history.temp* .
        b) Only 20 commands stored and 10 are printed is "history" is typed.
        c) History (int)M will print M commands but if M>20 it will only print 20 Max.

        Error : If input is wrong or If failed to create/read/write/open .history.temp file.

2)nightswatch :-
        -newborn :
                a) First output is also printed after "n" seconds.
                b) printf newly created process after every "n" seconds.
                c) used */proc/loadavg* file to get newly created process.
                d) May prinf previous process if no new process is created in previous "n" seconds.
                e) Exit on pressing q.

                Error : If wrong input given or unable open/read */proc/loadavg* file.

        -interrupt :
                a) First output is also printed after "n" seconds just like *newborn*.
                b) printf interrupt created after every "n" seconds.
                c) used */proc/interrupt* to printf keyboard interrupt.
                d) May printf same values if interrupt is same as n seconds before.
                e) Exit on pressing q.

                Error : If wrong input is given or unable read/open */proc/interrupt* file.
