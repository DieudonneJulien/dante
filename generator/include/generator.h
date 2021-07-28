/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** Contains prototypes of generator.
*/

#ifndef PREJECT_H_
#define PROJECT_H_

typedef struct map_s
{
    int lines;
    int cols;
    char **arr;
} map_t;

//errors.c
int errors(int ac, char const * const *av);

//generator.c
int generator(int ac, char const * const *av);

//create_map.c
map_t create_map(int l, int c);

//perfect_maze.c
int create_perfect_maze(map_t *map);

//find_way.c
int check_upper_cell(map_t *map, int *i, int *j);
int check_right_cell(map_t *map, int *i, int *j);
int check_lower_cell(map_t *map, int *i, int *j);
int check_left_cell(map_t *map, int *i, int *j);
int find_next_cell(map_t *map, int *i, int *j, int way);

//backtrack.c
void backtrack(map_t *map, int *i, int *j);
int end_of_backtrack(map_t *map, int *i, int *j);

//find_next_cell.c
int find_next_cel(map_t *map, int *i, int *j, int way);

#endif
