/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main of dante's generator.
*/

#include "generator.h"

int main(int ac, char const * const *av)
{
    errors(ac, av);
    generator(ac, av);
    return (0);
}
