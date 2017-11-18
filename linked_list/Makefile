TARGET=listTest
CC=gcc
OBJS=main.o linkedlist.o
SRCS=main.c linkedlist.c

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJS}

main.o: main.c linkedlist.h
linkedlist.o: linkedlist.c linkedlist.h
clean:
	rm *.o
