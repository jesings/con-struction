all:structfun.o ll2.o
	gcc structfun.o ll2.o -o structfun
structfun.o:structfun.c
	gcc -c structfun.c
ll2.o: ll2.c
	gcc -c ll2.c
run: all
	structfun
