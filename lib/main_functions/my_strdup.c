/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** A function that allocates memory and copies
** the string given as argument in it
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; i < my_strlen(src); i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
