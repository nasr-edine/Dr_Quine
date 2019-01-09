CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
EXEC=Colleen
SRC= C/Colleen.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

Colleen: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf C/*.o

fclean: clean
	rm -rf C/Colleen
	rm -rf Grace
	rm -rf C/tmp_Colleen
	rm -rf Grace_kid.c
	rm -rf C/folder/Sully*