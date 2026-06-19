CC=gcc

CFLAGS=-Wall

OBJ=main.o usuario.o log.o

usuarios: $(OBJ)
	$(CC) $(OBJ) -o usuarios

main.o: main.c usuario.h
	$(CC) $(CFLAGS) -c main.c

usuario.o: usuario.c usuario.h log.h
	$(CC) $(CFLAGS) -c usuario.c

log.o: log.c log.h
	$(CC) $(CFLAGS) -c log.c

clean:
	rm -f *.o usuarios
