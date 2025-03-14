/*
** EPITECH PROJECT, 2024
** clean str
** File description:
** clean str
*/

#include "my.h"

static int is_in(char *separators, char c)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i])
            return 1;
    }
    return 0;
}

static void if_dont_need(char *str, char *dst, int *spaceNeeded)
{
    if (dst != str && !(*spaceNeeded))
        *spaceNeeded = 1;
}

static void if_spaceneeded(char **dst, int *spaceNeeded)
{
    if (*spaceNeeded) {
        **dst = ' ';
        (*dst)++;
        *spaceNeeded = 0;
    }
}

void clean_str(char *str, char *separators)
{
    char *src = str;
    char *dst = str;
    int spaceNeeded = 0;

    while (*src) {
        if (!is_in(separators, *src)) {
            if_spaceneeded(&dst, &spaceNeeded);
            *dst = *src;
            dst++;
        } else {
            if_dont_need(str, dst, &spaceNeeded);
        }
        src++;
    }
    *dst = '\0';
}
