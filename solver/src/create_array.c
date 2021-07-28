/*
** EPITECH PROJECT, 2021
** create_array.c
** File description:
** Create structure.
*/

#include "solver.h"
#include <stdlib.h>

static int get_lines(char const *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            count = count + 1;
        i = i + 1;
    }
    return (count + 1);
}

static int get_cols(char const *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i = i + 1;
    return (i);
}

static int fill_array(char const *buffer, int k)
{
    if (buffer[k] == 'X')
        return (0);
    if (buffer[k] == '*')
        return (1);
    return (-1);
}

static int **create_array(char const *buffer, int lines, int cols)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int **arr = malloc(sizeof(int *) * (lines + 1));

    while (i < lines) {
        arr[i] = malloc(sizeof(int) * cols);
        while (j < cols) {
            arr[i][j] = fill_array(buffer, k);
            j = j + 1;
            k = k + 1;
        }
        j = 0;
        k = k + 1;
        i = i + 1;
    }
    arr[i] = NULL;
    return (arr);
}

map_t create_map(char const *buffer)
{
    map_t map;

    map.lines = get_lines(buffer);
    map.cols = get_cols(buffer);
    map.arr = create_array(buffer, map.lines, map.cols);
    return (map);
}
