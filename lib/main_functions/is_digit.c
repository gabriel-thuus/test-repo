/*
** EPITECH PROJECT, 2023
** is digit
** File description:
** is digit function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int is_digit(char *args)
{
    int i = 0;

    if (args[0] == '-')
        i = 1;
    for (i; args[i] != '\0'; i++) {
        if (args[i] < '0' || args[i] > '9')
            return 0;
    }
    return 1;
}
