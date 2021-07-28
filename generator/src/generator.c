/*
** EPITECH PROJECT, 2021
** generator.c
** File description:
** Main function of generator.
*/

#include "generator.h"
#include <stdlib.h>
#include <stdio.h>

static void free_map(map_t *map)
{
    int i = 0;

    while (i < map->lines) {
        free(map->arr[i]);
        i = i + 1;
    }
    free(map->arr);
}

static void print_map(map_t *map)
{
    int i = 0;

    while (i < map->lines) {
        if (i == map->lines - 1) {
            printf("%s", map->arr[i]);
        }
        else
            printf("%s\n", map->arr[i]);
        i = i + 1;
    }
}

static void change_tile(map_t *map, int ac, int i, int j)
{
    if (map->arr[i][j] == 'B') {
        if (ac == 3)
            map->arr[i][j] = '*';
        if (ac == 4)
            map->arr[i][j] = 'X';
    }
}

static void clear_maze(map_t *map, int ac)
{
    int i = 0;
    int j = 0;

    while (i < map->lines) {
        while (j < map->cols) {
            change_tile(map, ac, i, j);
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
}

int generator(int ac, char const * const *av)
{
    map_t map = create_map(atoi(av[2]), atoi(av[1]));

    create_perfect_maze(&map);
    clear_maze(&map, ac);
    print_map(&map);
    free_map(&map);
    return (0);
}
