/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** Create struct map.
*/

#include "generator.h"
#include <stdlib.h>

static char **create_array(int l, int c)
{
    int i = 0;
    int j = 0;
    char **arr = malloc(sizeof(int *) * (l + 1));

    while (i < l) {
        arr[i] = malloc(sizeof(int) * (c + 1));
        while (j < c) {
            arr[i][j] = 'X';
            j = j + 1;
        }
        arr[i][j] = '\0';
        j = 0;
        i = i + 1;
    }
    arr[i] = NULL;
    return (arr);
}

map_t create_map(int l, int c)
{
    map_t map;

    map.lines = l;
    map.cols = c;
    map.arr = create_array(l, c);
    return (map);
}
