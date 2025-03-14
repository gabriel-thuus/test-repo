/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "asm.h"

static void free_struct(infos **info_file)
{
    for (int i = 0; (*info_file)->big_tab[i] != NULL; i++)
        free_tab((*info_file)->big_tab[i]);
    free((*info_file)->big_tab);
    free((*info_file)->file_name);
    if ((*info_file)->labels)
        free_tab((*info_file)->labels);
    free((*info_file));
}

static int empty_file(int fd, struct stat *st, char **av)
{
    char *buf = NULL;
    int i = 0;
    char **tab = NULL;

    buf = malloc(sizeof(char) * (st->st_size + 1));
    i = read(fd, buf, st->st_size);
    tab = my_str_to_word_array(av[1], "/");
    if (i == 0) {
        my_printf("asm, %s: The file is empty.\n", tab[len_tab(tab) - 1]);
        free_tab(tab);
        free(buf);
        close(fd);
        return 84;
    }
    free_tab(tab);
    free(buf);
    close(fd);
    return 0;
}

int wrong_file(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat st;
    char *buf = NULL;

    if (fd == -1) {
        write(2, "Error in function open: No such file or directory.\n", 52);
        close(fd);
        return 84;
    }
    stat(av[1], &st);
    if (!S_ISREG(st.st_mode)) {
        write(2, "asm: Error in function read: Is a directory.\n", 46);
        close(fd);
        return 84;
    }
    return empty_file(fd, &st, av);
}

int asm_to_cor(infos **info_file, FILE *file)
{
    FILE *file_cor = NULL;
    char *name = NULL;

    if (parsing(info_file, file)) {
        free_struct(info_file);
        return 84;
    }
    my_strncpy(&name, (*info_file)->file_name,
        my_strlen((*info_file)->file_name) - 2);
    name = my_strcat(name, my_strdup(".cor"));
    file_cor = fopen(name, "w");
    head(info_file, file_cor);
    free(name);
    free_struct(info_file);
    fclose(file_cor);
    return 0;
}

static void initialize_struct(infos **info_file, char **av)
{
    char **tab = my_str_to_word_array(av[1], "/");

    *info_file = malloc(sizeof(infos));
    (*info_file)->file_name = my_strdup(tab[len_tab(tab) - 1]);
    (*info_file)->end_header = 0;
    (*info_file)->labels = NULL;
    (*info_file)->prog_size = 0;
    free_tab(tab);
}

int main(int ac, char **av)
{
    FILE *file;
    infos *info_file;

    if (ac != 2) {
        write(2, "Look at ./asm -h.\n", 19);
        return 84;
    }
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage();
    if (wrong_file(ac, av))
        return 84;
    file = fopen(av[1], "rb");
    initialize_struct(&info_file, av);
    return asm_to_cor(&info_file, file);
}
