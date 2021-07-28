/*
** EPITECH PROJECT, 2021
** get_solution.c
** File description:
** Get solution.
*/

#include "solver.h"

static void get_solution_tile(map_t *map, int *i, int *j, int k)
{
    if (*i != 0 && map->arr[*i - 1][*j] == k) {
        map->arr[*i - 1][*j] = -1;
        *i = *i - 1;
        return;
    }
    if (*j != map->cols - 1 && map->arr[*i][*j + 1] == k) {
        map->arr[*i][*j + 1] = -1;
        *j = *j + 1;
        return;
    }
    if (*i != map->lines - 1 && map->arr[*i + 1][*j] == k) {
        map->arr[*i + 1][*j] = -1;
        *i = *i + 1;
        return;
    }
    if (*j != 0 && map->arr[*i][*j - 1] == k) {
        map->arr[*i][*j - 1] = -1;
        *j = *j - 1;
        return;
    }
}

void get_solution(map_t *map)
{
    int i = map->lines - 1;
    int j = map->cols - 1;
    int k = map->arr[map->lines - 1][map->cols - 1] - 1;

    map->arr[map->lines - 1][map->cols - 1] = -1;
    while (map->arr[0][0] == 2) {
        get_solution_tile(map, &i, &j, k);
        k = k - 1;
    }
}
