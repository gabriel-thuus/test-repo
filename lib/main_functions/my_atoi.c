/*
** EPITECH PROJECT, 2023
** my_atoi.c
** File description:
** my atoi
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

char *my_atoi(int nb)
{
    int len_nb = my_intlen(nb);
    char *str = malloc(sizeof(char) * (len_nb + 1));
    int div = pow_10(1, len_nb - 1);
    char c;
    int i = 0;

    for (i = 0; i < my_intlen(nb); i++) {
        c = ((nb / div) % 10) + 48;
        str[i] = c;
        div = div / 10;
    }
    str[i] = '\0';
    return str;
}
