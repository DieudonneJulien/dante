/*
** EPITECH PROJECT, 2021
** find_next_cell.c
** File description:
** Find next cell.
*/

#include "generator.h"

int find_next_cel(map_t *map, int *i, int *j, int way)
{
    if (way == 0 && *i != 0 && map->arr[*i - 1][*j] == 'X')
        return (find_next_cell(map, i, j, way));
    if (way == 1 && *j < map->cols - 1 && map->arr[*i][*j + 1] == 'X')
        return (find_next_cell(map, i, j, way));
    if (way == 2 && *i < map->lines - 1 && map->arr[*i + 1][*j] == 'X')
        return (find_next_cell(map, i, j, way));
    if (way == 3 && *j != 0 && map->arr[*i][*j - 1] == 'X')
        return (find_next_cell(map, i, j, way));
    return (0);
}
