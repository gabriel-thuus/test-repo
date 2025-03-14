/*
** EPITECH PROJECT, 2024
** do big tab
** File description:
** do the tab of tab
*/

#include "asm.h"

static void check_line(infos **info_file, int i, char *line, int *val)
{
    if (is_empty_line(line)) {
        (*info_file)->big_tab[i] = malloc(sizeof(char *) * 2);
        (*info_file)->big_tab[i][0] = my_strdup(" ");
        (*info_file)->big_tab[i][1] = NULL;
    } else {
        if (*val < 2)
            (*info_file)->big_tab[i] = my_str_to_word_array(line, " \t;");
        else
            (*info_file)->big_tab[i] = my_str_to_word_array(line, " \t,");
        (*val)++;
    }
}

static void add_line(infos **info_file, FILE *file, int *i)
{
    char *line = NULL;
    size_t nb = 0;
    int v = 0;
    int val = 0;

    v = getline(&line, &nb, file);
    for (*i = 0; v != -1; (*i)++) {
        (*info_file)->big_tab =
            realloc((*info_file)->big_tab, ((*i) + 1) * sizeof(char **));
        clean_str(line, "\n");
        check_line(info_file, *i, line, &val);
        free(line);
        line = NULL;
        v = getline(&line, &nb, file);
    }
    free(line);
}

void do_big_tab(infos **info_file, FILE *file)
{
    int i = 0;

    (*info_file)->big_tab = NULL;
    add_line(info_file, file, &i);
    (*info_file)->big_tab =
        realloc((*info_file)->big_tab, (i + 1) * sizeof(char **));
    (*info_file)->big_tab[i] = NULL;
    fclose(file);
}
