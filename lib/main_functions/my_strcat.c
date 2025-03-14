/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** A function that concatenates two strings and free these strings after
** making the new string
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j;
    char *dest2 = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i] != '\0') {
        dest2[i] = dest[i];
        i++;
    }
    for (j = 0; src[j] != '\0'; j++) {
        dest2[i + j] = src[j];
    }
    dest2[i + j] = '\0';
    free(dest);
    free(src);
    return dest2;
}
