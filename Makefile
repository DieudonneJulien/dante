##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## dante
##

all:
		make -C solver/
		make -C generator/

clean:		clean -C solver/
		clean -C generator/

fclean:		fclean -C solver/
		fclean -C generator/

re:		fclean all

.PHONY:		all clean fclean re
