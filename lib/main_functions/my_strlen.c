/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** A function thats counts and returns the number of character
** found in the string passed as parameter
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
