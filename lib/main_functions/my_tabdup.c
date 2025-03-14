/*
** EPITECH PROJECT, 2024
** my_tabdup
** File description:
** tabdup
*/

#include "my.h"

char **my_tabdup(char **env)
{
    char **tab;
    int count = 0;

    for (count; env[count] != NULL; count++);
    tab = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; env[i] != NULL; i++)
        tab[i] = my_strdup(env[i]);
    tab[count] = NULL;
    return tab;
}
