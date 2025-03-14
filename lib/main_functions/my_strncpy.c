/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** A function that copies n characters from a string
** into another
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void my_strncpy(char **dest, char *src, int nb)
{
    if (my_strlen(src) <= nb)
        nb = my_strlen(src);
    *dest = malloc(sizeof(char) * (nb + 1));
    for (int i = 0; i < nb; i++) {
        (*dest)[i] = src[i];
    }
    (*dest)[nb] = '\0';
}
