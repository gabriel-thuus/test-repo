/*
** EPITECH PROJECT, 2024
** load file in mem
** File description:
** load file in mem
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    char *buf;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "open: No such file or directory\n", 33);
        exit(84);
    }
    stat(filepath, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (read(fd, buf, st.st_size) == 0) {
        free(buf);
        write(1, "Nothing to read\n", 17);
        exit(84);
    }
    buf[st.st_size] = '\0';
    return buf;
}
