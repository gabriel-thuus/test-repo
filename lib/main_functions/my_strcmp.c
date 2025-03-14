/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** oui
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i++;
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }
    }
    if (s1[i] != s2[i]) {
        return (int)s1[i] - (int)s2[i];
    }
    return 0;
}
