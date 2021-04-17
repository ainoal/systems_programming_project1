reverse: readwrite.o reverse.o
	gcc reverse.o readwrite.o -o reverse -std=c99 -Wall -Wno-comment -pedantic
reverse.o: reverse.c readwrite.h
	gcc reverse.c -c -std=c99 -Wall -Wno-comment -pedantic
readwrite.o: readwrite.c readwrite.h
	gcc readwrite.c -c -std=c99 -Wall -Wno-comment -pedantic
