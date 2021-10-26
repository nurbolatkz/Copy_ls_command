
#OUTPUT file myls: ./myls ls -a 
CC = gcc
CFLAGS  = -Wall -Wextra -Werror -g3 -fsanitize=address


myls: main.o mylsfunc.o sorts.o display.o readdir.o stringfun.o
	$(CC) $(CFLAGS) -o myls mylsfunc.o main.o  sorts.o display.o readdir.o stringfun.o
main.o:  mainls.c
	$(CC) $(CFLAGS) -c -o main.o mainls.c
mylsfunc.o: mylsfunc.c
	$(CC) $(CFLAGS) -c -o mylsfunc.o mylsfunc.c
sorts.o: sorts.c
	$(CC) $(CFLAGS) -c -o sorts.o sorts.c
display.o: display.c
	$(CC) $(CFLAGS) -c -o display.o display.c
readdir.o: readdir.c
	$(CC) $(CFLAGS) -c -o readdir.o readdir.c
stringfun.o: stringfun.c
	$(CC) $(CFLAGS) -c -o stringfun.o stringfun.c
clean: 
	$(RM) count *.o *~