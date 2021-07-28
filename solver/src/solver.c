/*
** EPITECH PROJECT, 2021
** solver.c
** File description:
** Solver.
*/

#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

static void print_tile(map_t *map, int i, int j)
{
    if (map->arr[i][j] == -1)
        printf("o");
    else if (map->arr[i][j] == 0)
        printf("X");
    else
        printf("*");
}

static void print_map(map_t *map)
{
    int i = 0;
    int j = 0;

    while (i < map->lines) {
        while (j < map->cols) {
            print_tile(map, i, j);
            j = j + 1;
        }
        if (i != map->lines - 1)
            printf("\n");
        j = 0;
        i = i + 1;
    }
}

static void free_map(map_t *map)
{
    int i = 0;

    while (i < map->lines) {
        free(map->arr[i]);
        i = i + 1;
    }
    free(map->arr);
}

int solver(char const *buffer)
{
    map_t map = create_map(buffer);

    solve_maze(&map);
    print_map(&map);
    free_map(&map);
    return (0);
}
