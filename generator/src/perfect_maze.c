/*
** EPITECH PROJECT, 2021
** perfect_maze.c
** File description:
** Create a perfect maze.
*/

#include "generator.h"
#include <stdlib.h>
#include <time.h>

static int is_way_stuck(map_t *map, int *i, int *j)
{
    int k = 0;

    if (*i == 0 || map->arr[*i - 1][*j] != 'X'
        || check_upper_cell(map, i, j) == 1)
        k = k + 1;
    if (*j == map->cols - 1 || map->arr[*i][*j + 1] != 'X'
        || check_right_cell(map, i, j) == 1)
        k = k + 1;
    if (*i == map->lines - 1 || map->arr[*i + 1][*j] != 'X'
        || check_lower_cell(map, i, j) == 1)
        k = k + 1;
    if (*j == 0 || map->arr[*i][*j - 1] != 'X'
        || check_left_cell(map, i, j) == 1)
        k = k + 1;
    if (k == 4)
        return (1);
    return (0);
}

static void create_way(map_t *map, int *i, int *j, int r)
{
    int done = 0;
    int way = -1;
    time_t timep = time(NULL);

    while (done == 0) {
        gmtime(&timep);
        way = difftime(timep, 0) + r;
        srand(way);
        way = (int)rand() + r;
        way = way % 4;
        r = r + 1;
        done = find_next_cel(map, i, j, way);
    }
}

static int create_end_tile(map_t *map, int *i, int *j)
{
    if (map->arr[map->lines - 1][map->cols - 1] == 'X') {
        if (*i == map->lines - 1 && *j == map->cols - 2) {
            *j = *j + 1;
            map->arr[*i][*j] = 'B';
            return (1);
        }
        if (*i == map->lines - 2 && *j == map->cols - 1) {
            *i = *i + 1;
            map->arr[*i][*j] = 'B';
            return (1);
        }
    }
    return (0);
}

static void create_path(map_t *map, int *i, int *j, int r)
{
    if (create_end_tile(map, i, j) == 1)
        return;
    create_way(map, i, j, r);
}

int create_perfect_maze(map_t *map)
{
    int i = 0;
    int j = 0;
    int r = 0;
    int end = 0;

    map->arr[0][0] = 'B';
    while (end == 0) {
        if (is_way_stuck(map, &i, &j) == 1) {
            end = end_of_backtrack(map, &i, &j);
            backtrack(map, &i, &j);
        }
        else
            create_path(map, &i, &j, r);
        r = r + 1;
    }
    return (0);
}
