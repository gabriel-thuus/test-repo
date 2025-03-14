/*
** EPITECH PROJECT, 2024
** labels
** File description:
** labels
*/

#include "../asm.h"

int is_label(infos **info_file, char *str)
{
    char **label_tab = (*info_file)->labels;

    for (int i = 0; label_tab[i] != NULL; i++) {
        if (!my_strncmp(str, label_tab[i], my_strlen(label_tab[i]) - 1))
            return 1;
    }
    return 0;
}

static int label_already_exist(infos **info_file, char ***tab, int v, int i)
{
    for (int j = 0; j < v; j++) {
        if (!my_strcmp(tab[i][0], (*info_file)->labels[j]))
            return i;
    }
    return 0;
}

static int put_labels_in_tab(infos **info_file, char ***tab, int nb)
{
    int len = 0;
    int v = 0;
    int val = 0;

    (*info_file)->labels = malloc(sizeof(char *) * (nb + 1));
    for (int i = 0; tab[i] != NULL; i++) {
        len = my_strlen(tab[i][0]);
        val = label_already_exist(info_file, tab, v, i);
        if (val != 0)
            return val;
        if (tab[i][0][len - 1] == LABEL_CHAR && is_valid(tab[i][0])) {
            (*info_file)->labels[v] = my_strdup(tab[i][0]);
            v++;
        }
    }
    (*info_file)->labels[nb] = NULL;
    return 1;
}

static int is_empty(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = 'A';
    }
    return 1;
}

static int is_unique_labels(infos **info_file, char ***tab, int nb)
{
    int v = 0;

    v = put_labels_in_tab(info_file, tab, nb);
    if (v != 1) {
        my_printf("asm, %s, line %d: Multiple definition of the same label.\n",
            (*info_file)->file_name, v + 1);
        return 0;
    }
    return 1;
}

static int label(infos **info_file, char ***tab, int i, int *nb)
{
    int len = 0;

    clean_str(tab[i][0], " \t");
    len = my_strlen(tab[i][0]);
    if (tab[i][0][len - 1] == LABEL_CHAR && is_valid(tab[i][0]))
        (*nb)++;
    if (tab[i][0][len - 1] == LABEL_CHAR && !is_valid(tab[i][0])) {
        my_printf("asm, %s, line %d: Invalid label name.\n",
            (*info_file)->file_name, i + 1);
        return 0;
    }
    return 1;
}

int find_labels(infos **info_file)
{
    char ***tab = (*info_file)->big_tab;
    int len = 0;
    int nb = 0;
    int v = 0;

    (*info_file)->labels = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        if ((*info_file)->big_tab[i][0][0] == '#' ||
            (*info_file)->big_tab[i][0][0] == ' ')
            continue;
        if (!label(info_file, tab, i, &nb))
            return 0;
    }
    return is_unique_labels(info_file, tab, nb);
}
