/*
** EPITECH PROJECT, 2023
** my_floatlen
** File description:
** a function that return the number of characters of a float
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int pow_10(int pow, int coma)
{
    for (int i = 0; i < coma; i++)
        pow *= 10;
    return pow;
}

int my_floatlen(double nb, int coma)
{
    long tmp = 0;
    int nb_char = 1;

    nb_char += my_intlen((int)nb) + coma;
    return nb_char;
}
