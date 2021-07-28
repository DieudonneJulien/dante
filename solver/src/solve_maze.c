/*
** EPITECH PROJECT, 2021
** solve_maze.c
** File description:
** Solve a maze.
*/

#include "solver.h"
#include <stdlib.h>

static int special_case(map_t *map)
{
    if (map->arr[0][0] == 0)
        return (1);
    if (map->arr[map->lines - 1][map->cols - 1] == 0)
        return (1);
    return (0);
}

static int find_next_way(map_t *map, int i, int j, int k)
{
    if (map->arr[i][j] == k) {
        if (i != 0 && map->arr[i - 1][j] == 1)
            map->arr[i - 1][j] = k + 1;
        if (j != map->cols - 1 && map->arr[i][j + 1] == 1)
            map->arr[i][j + 1] = k + 1;
        if (i != map->lines - 1 && map->arr[i + 1][j] == 1)
            map->arr[i + 1][j] = k + 1;
        if (j != 0 && map->arr[i][j - 1] == 1)
            map->arr[i][j - 1] = k + 1;
        return (1);
    }
    return (0);
}

static int fill_maze(map_t *map, int k)
{
    int i = 0;
    int j = 0;
    int test = 0;

    while (i < map->lines) {
        while (j < map->cols) {
            test = find_next_way(map, i, j, k) + test;
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    if (test != 0)
        return (0);
    return (1);
}

int solve_maze(map_t *map)
{
    int k = 2;

    if (special_case(map) == 1)
        return (1);
    map->arr[0][0] = 2;
    while (map->arr[map->lines - 1][map->cols - 1] < 2) {
        if (fill_maze(map, k) == 1)
            return (1);
        k = k + 1;
    }
    get_solution(map);
    return (0);
}
