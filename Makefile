CFLAGS = -Wall

default : shell

shell: main.c back_front_process.c cd.c check_process.c cmd_hndl.c color.c echo.c history.c ls.c nightswatch.c pinfo.c pwd.c input.h header.h
	gcc $(CFLAGS) main.c back_front_process.c cd.c check_process.c cmd_hndl.c color.c echo.c history.c ls.c nightswatch.c pinfo.c pwd.c -o shell

clean:
	rm shell