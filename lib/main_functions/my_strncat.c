/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** oui
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j;

    while (dest[i] != '\0') {
        i++;
    }
    for (j = 0; src[j] != '\0' && j < nb; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return dest;
}
