CC=clang
CFLAGS=-Wall -Wextra -Werror
EXEC=Colleen
SRC= Colleen.c
OBJ= $(SRC:.c=.o)

all: Colleen Grace Sully

Colleen: Colleen.c
	clang $(CFLAGS) -o Colleen Colleen.c
	
Grace: Grace.c
	clang $(CFLAGS) -o Grace Grace.c

Sully: Sully.c
	clang $(CFLAGS) -o Sully Sully.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf Colleen
	rm -rf Grace
	rm -rf tmp_Colleen
	rm -rf Grace_kid.c
	rm -rf Sully
	rm -rf tmp/Sully*