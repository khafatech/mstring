
main:	main.o mstring.o
		gcc -Wall $^ -o $@

main.o: main.c
		gcc -Wall -c $<

mstring.o:	mstring.c mstring.h
	gcc -Wall -c $<


clean:
	rm *.o


