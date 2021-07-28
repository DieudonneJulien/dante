/*
** EPITECH PROJECT, 2021
** errors.c
** File description:
** Error handling of solver.
*/

static int check_buffer(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '*' && str[i] != 'X' && str[i] != '\n')
            return (84);
        i = i + 1;
    }
    return (0);
}

static int check_line_lenght(char const *str)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        count = count + 1;
        i = i + 1;
    }
    if (str[i] == '\0')
        return (0);
    i = i + 1;
    while (str[i] != '\0') {
        if (str[i] == '\n' && j != count)
            return (84);
        if (str[i] == '\n')
            j = -1;
        i = i + 1;
        j = j + 1;
    }
    return (0);
}

int errors(char const *str)
{
    if (check_buffer(str) == 84)
        return (84);
    if (check_line_lenght(str) == 84)
        return (84);
    return (0);
}
