reverse: readwrite.o reverse.o
	gcc reverse.o readwrite.o -o reverse -Wall -pedantic
reverse.o: reverse.c readwrite.h
	gcc reverse.c -c -Wall -pedantic
readwrite.o: readwrite.c readwrite.h
	gcc readwrite.c -c -Wall -pedantic
