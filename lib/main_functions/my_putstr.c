/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** A function that displays one-by-one, the characters of a string
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
