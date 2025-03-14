/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** A function that copies a string into another
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
