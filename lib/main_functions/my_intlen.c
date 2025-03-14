/*
** EPITECH PROJECT, 2023
** my_intlen
** File description:
** function that count the number of characters in an integer
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

int my_intlen(long nb)
{
    int nb_char = 1;

    for (nb_char = 0; nb >= 1; nb_char++)
        nb = nb / 10;
    return nb_char;
}
