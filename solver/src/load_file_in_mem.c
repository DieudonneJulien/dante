/*
** EPITECH PROJECT, 2021
** load_file_in_mem.c
** File description:
** Load file.
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat sb;
    int fd;
    char *buff;
    int size;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        return (NULL);
    }
    stat(filepath, &sb);
    size = sb.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    if (read(fd, buff, size) == -1) {
        if (buff != NULL)
            free(buff);
        return (NULL);
    }
    buff[size] = '\0';
    return (buff);
}
