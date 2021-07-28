/*
** EPITECH PROJECT, 2021
** errors.c
** File description:
** Handle errors of dante's generator.
*/

#include <stdlib.h>

static int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    if (s1[i] == '\0')
        return (-1);
    if (s2[i] == '\0')
        return (1);
    return (0);
}

static void check_nbrs(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            exit(84);
        i++;
    }
}

int errors(int ac, char const * const *av)
{
    if (ac == 3) {
        check_nbrs(av[1]);
        check_nbrs(av[2]);
        return (0);
    }
    if (ac == 4) {
        check_nbrs(av[1]);
        check_nbrs(av[2]);
        if (my_strcmp(av[3], "perfect") != 0)
            exit(84);
        return (0);
    }
    exit(84);
}
