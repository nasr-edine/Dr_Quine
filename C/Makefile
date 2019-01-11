CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
EXEC=Colleen
SRC= Colleen.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

Colleen: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf Colleen
	rm -rf Grace
	rm -rf tmp_Colleen
	rm -rf Grace_kid.c
	rm -rf folder/Sully*