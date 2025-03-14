/*
** EPITECH PROJECT, 2024
** transform tab
** File description:
** functions for tab
*/

#include "asm.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int len_tab(char **tab)
{
    int i = 0;

    for (i; tab[i]; i++);
    return i;
}

static void tab_to_str(char ***tab)
{
    char *param = my_strdup((*tab)[0]);
    char *str = my_strdup((*tab)[1]);

    free((*tab)[1]);
    for (int i = 2; (*tab)[i] != NULL; i++) {
        str = my_strcat(str, my_strdup(" "));
        str = my_strcat(str, (*tab)[i]);
    }
    (*tab) = malloc(sizeof(char *) * 3);
    (*tab)[0] = my_strdup(param);
    (*tab)[1] = my_strdup(str);
    (*tab)[2] = NULL;
    free(param);
    free(str);
}

void modify_tab(infos **info_file, int idx_name, int idx_cmt)
{
    if (len_tab((*info_file)->big_tab[idx_name]) > 2)
        tab_to_str(&(*info_file)->big_tab[idx_name]);
    if (len_tab((*info_file)->big_tab[idx_cmt]) > 2)
        tab_to_str(&(*info_file)->big_tab[idx_cmt]);
}
