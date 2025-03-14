/*
** EPITECH PROJECT, 2024
** valid str
** File description:
** str
*/

#include "asm.h"

int is_in(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (c == LABEL_CHARS[i])
            return 1;
    }
    return 0;
}

int is_valid(char *str)
{
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if (!is_in(str[i]))
            return 0;
    }
    return 1;
}

static int begin_str(char *str, int *i)
{
    for (*i; str[(*i)] != '"'; (*i)++) {
        if (str[(*i)] == '\0')
            return 0;
    }
    return 1;
}

static int end_str(char *str, int *i)
{
    for (*i += 1; str[(*i)] != '\0'; i++) {
        if (str[(*i)] != ' ' && str[(*i)] != '#')
            return 0;
        if (str[(*i)] == '#')
            break;
    }
    return 1;
}

int valid_str(char *str)
{
    int v = 0;
    int i = 1;

    if (str[0] == '"') {
        if (!begin_str(str, &i))
            return 0;
        if (!end_str(str, &i))
            return 0;
    }
    return 1;
}
