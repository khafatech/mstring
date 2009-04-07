
main:	main.o mstring.o
		gcc -Wall $? -o main

main.o: main.c
		gcc -Wall -c $?

mstring.o:	mstring.c mstring.h
	gcc -Wall -c mstring.c


clean:
	rm *.o


