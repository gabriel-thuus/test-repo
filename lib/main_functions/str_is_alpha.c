/*
** EPITECH PROJECT, 2024
** check if the string is alphanumeric only
** File description:
** str is alpha
*/

#include "my.h"

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int str_is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alpha(str[i]))
            return 0;
    }
    return 1;
}
