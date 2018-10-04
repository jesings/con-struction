all:structfun.o ll2.o ll2.h node.h
	gcc structfun.o ll2.o -o structfun
structfun.o:structfun.c node.h
	gcc -c structfun.c
ll2.o: ll2.c ll2.h node.h
	gcc -c ll2.c
run: all
	./structfun
