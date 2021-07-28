/*
** EPITECH PROJECT, 2021
** find_way.c
** File description:
** Find next cell.
*/

#include "generator.h"

int check_upper_cell(map_t *map, int *i, int *j)
{
    if (*i > 1 && map->arr[*i - 2][*j] != 'X')
        return (1);
    if (*i > 0 && *j > 0 && map->arr[*i - 1][*j - 1] != 'X')
        return (1);
    if (*i > 1 && *j < map->cols - 1 && map->arr[*i - 1][*j + 1] != 'X')
        return (1);
    return (0);
}

int check_right_cell(map_t *map, int *i, int *j)
{
    if (*j < map->cols - 2 && map->arr[*i][*j + 2] != 'X')
        return (1);
    if (*i < map->lines - 1 && *j < map->cols - 1
        && map->arr[*i + 1][*j + 1] != 'X')
        return (1);
    if (*i > 1 && *j < map->cols - 1 && map->arr[*i - 1][*j + 1] != 'X')
        return (1);
    return (0);
}

int check_lower_cell(map_t *map, int *i, int *j)
{
    if (*i < map->lines - 2 && map->arr[*i + 2][*j] != 'X')
        return (1);
    if (*i < map->lines - 1 && *j < map->cols - 1
        && map->arr[*i + 1][*j + 1] != 'X')
        return (1);
    if (*i < map->lines - 1 && *j > 0
        && map->arr[*i + 1][*j - 1] != 'X')
        return (1);
    return (0);
}

int check_left_cell(map_t *map, int *i, int *j)
{
    if (*j > 1 && map->arr[*i][*j - 2] != 'X')
        return (1);
    if (*i < map->lines - 1 && *j > 0
        && map->arr[*i + 1][*j - 1] != 'X')
        return (1);
    if (*i > 0 && *j > 0 && map->arr[*i - 1][*j - 1] != 'X')
        return (1);
    return (0);
}

int find_next_cell(map_t *map, int *i, int *j, int way)
{
    if (way == 0 && check_upper_cell(map, i, j) == 0) {
        *i = *i - 1;
        map->arr[*i][*j] = 'B';
        return (1);
    }
    if (way == 1 && check_right_cell(map, i, j) == 0) {
        *j = *j + 1;
        map->arr[*i][*j] = 'B';
        return (1);
    }
    if (way == 2 && check_lower_cell(map, i, j) == 0) {
        *i = *i + 1;
        map->arr[*i][*j] = 'B';
        return (1);
    }
    if (way == 3 && check_left_cell(map, i, j) == 0) {
        *j = *j - 1;
        map->arr[*i][*j] = 'B';
        return (1);
    }
    return (0);
}
