##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## generator
##

SRC	=	src/main.c\
		src/errors.c\
		src/generator.c\
		src/create_map.c\
		src/perfect_maze.c\
		src/find_way.c\
		src/backtrack.c\
		src/find_next_cell.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS =	-I./include/

CFLAGS	=	-W -Wall -Wextra

NAME	=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f include/*~
		rm -f src/*~
		rm -f *~

re:		fclean all

.PHONY:		all clean fclean re
