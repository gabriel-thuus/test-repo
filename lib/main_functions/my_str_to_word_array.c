/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** A function that splits a string into words
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int is_in(char c, char *ref)
{
    for (int i = 0; ref[i] != '\0'; i++) {
        if (c == ref[i])
            return 1;
    }
    return 0;
}

static int is_alphanum(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

static int nb_words(char const *str, char *ref)
{
    int i = 0;
    int nb = 0;

    while (is_in(str[i], ref) && str[i] != '\0') {
        i++;
    }
    while (str[i] != '\0') {
        while (!is_in(str[i], ref) && str[i] != '\0') {
            i++;
        }
        while (is_in(str[i], ref) && str[i] != '\0') {
            i++;
        }
        nb++;
    }
    return nb;
}

static void size_words(char const *str, char **tab, char *ref)
{
    int i = 0;
    int v = 0;
    int length = 0;

    while (str[i] != '\0') {
        while (is_in(str[i], ref) && str[i] != '\0') {
            i++;
        }
        while (!is_in(str[i], ref) && str[i] != '\0') {
            i++;
            length++;
        }
        tab[v] = malloc(sizeof(char) * (length + 1));
        v++;
        length = 0;
    }
}

static char print_in_tab(char const *str, char **tab, int nb, char *ref)
{
    int width = 0;
    int length = 0;
    int k = 0;

    while (str[k] != '\0') {
        length = 0;
        while (is_in(str[k], ref) && str[k] != '\0') {
            k++;
        }
        while (!is_in(str[k], ref) && str[k] != '\0') {
            tab[width][length] = str[k];
            k++;
            length++;
        }
        tab[width][length] = '\0';
        width++;
    }
    tab[nb] = NULL;
}

char **my_str_to_word_array(char const *str, char *ref)
{
    int nb_w = nb_words(str, ref);
    char **tab;

    tab = malloc(sizeof(char *) * (nb_w + 1));
    size_words(str, tab, ref);
    print_in_tab(str, tab, nb_w, ref);
    return tab;
}
