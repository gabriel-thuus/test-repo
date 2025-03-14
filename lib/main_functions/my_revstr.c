/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** A function that reverses a string
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str);
    char c;

    for (; i < j; i++) {
        j--;
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return str;
}
