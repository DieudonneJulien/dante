/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main of dante's solver.
*/

#include "solver.h"
#include <stddef.h>
#include <stdlib.h>

int main(int ac, char const * const *av)
{
    char *buff = NULL;

    if (ac != 2)
        return (84);
    buff = load_file_in_mem(av[1]);
    if (buff == NULL)
        return (84);
    if (errors(buff) == 84) {
        free(buff);
        return (84);
    }
    solver(buff);
    free(buff);
    return (0);
}
