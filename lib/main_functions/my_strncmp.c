/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** strncmp function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return 0;
    for (i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            break;
    }
    if (i == n)
        return 0;
    return (char)s1[i] - (char)s2[i];
}
