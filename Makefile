##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= lem_in

CC	= gcc

RM	= rm -f

SRC	= 	src/errors/errors.c				\
		src/errors/rooms.c				\
		src/errors/tunnels.c			\
		src/structs/initialization.c	\
		src/structs/add_elements.c		\
		src/way/find_way.c				\
		src/way/init_way.c				\
		src/lib.c						\
		src/main.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy

all: $(NAME)

$(NAME):
	cd lib/my && make re
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
