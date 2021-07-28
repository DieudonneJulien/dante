/*
** EPITECH PROJECT, 2021
** backtrack.c
** File description:
** Function of backtracking.
*/

#include "generator.h"

void backtrack(map_t *map, int *i, int *j)
{
    if (*i != 0 && map->arr[*i - 1][*j] == 'B') {
        map->arr[*i][*j] = '*';
        *i = *i - 1;
        return;
    }
    if (*j != map->cols - 1 && map->arr[*i][*j + 1] == 'B') {
        map->arr[*i][*j] = '*';
        *j = *j + 1;
        return;
    }
    if (*i != map->lines - 1 && map->arr[*i + 1][*j] == 'B') {
        map->arr[*i][*j] = '*';
        *i = *i + 1;
        return;
    }
    if (*j != 0 && map->arr[*i][*j - 1] == 'B') {
        map->arr[*i][*j] = '*';
        *j = *j - 1;
        return;
    }
}

int end_of_backtrack(map_t *map, int *i, int *j)
{
    if (*i == 0 && *j == 0) {
        map->arr[0][0] = '*';
        return (1);
    }
    return (0);
}
