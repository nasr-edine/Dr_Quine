CC=clang
CFLAGS=-Wall -Wextra -Werror
NAME=Colleen Grace Sully
SRC= Colleen.c Grace.c Sully.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

Colleen: Colleen.c
	clang $(CFLAGS) -o Colleen Colleen.c
	
Grace: Grace.c
	clang $(CFLAGS) -o Grace Grace.c

Sully: Sully.c
	clang $(CFLAGS) -o Sully Sully.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f tmp_Colleen
	rm -f Grace_kid.c
	rm -rf tmp

re: fclean all

.PHONY: all clean fclean re