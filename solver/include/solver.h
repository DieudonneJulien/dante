/*
** EPITECH PROJECT, 2020
** solver.h
** File description:
** Contains prototypes of solver.
*/

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct map_s
{
    int lines;
    int cols;
    int **arr;
} map_t;

//load_file_in_mem.c
char *load_file_in_mem(char const *filepath);

//solver.c
int solver(char const *buffer);

//create_array.c
map_t create_map(char const *buffer);

//solve_maze.c
int solve_maze(map_t *map);

//get_solution.c
void get_solution(map_t *map);

//errors.c
int errors(char const *str);

#endif
