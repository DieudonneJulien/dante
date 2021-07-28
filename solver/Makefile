##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## solver
##

SRC	=	src/main.c\
		src/load_file_in_mem.c\
		src/solver.c\
		src/create_array.c\
		src/solve_maze.c\
		src/get_solution.c\
		src/errors.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS =	-I./include/

CFLAGS	=	-W -Wall -Wextra

NAME	=	solver

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
