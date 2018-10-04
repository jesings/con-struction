all:structfun.o ll2.o bastrlib.o
	gcc structfun.o ll2.o bastrlib.o -o structfun
structfun.o:structfun.c node.h ll2.h
	gcc -c structfun.c
ll2.o: ll2.c ll2.h node.h bastrlib.h
	gcc -c ll2.c
bastrlib.o: bastrlib.c bastrlib.h
	gcc -c bastrlib.c
run: all
	./structfun
