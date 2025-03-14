/*
** EPITECH PROJECT, 2023
** my_putfloat
** File description:
** a function that returns a float
*/

#include "my.h"

static int pow_10(int pow, int coma)
{
    for (int i = 0; i < coma; i++)
        pow *= 10;
    return pow;
}

static void display_float(long val, int pow)
{
    my_put_nbr(val / pow);
    my_putchar('.');
    while (pow != 10) {
        my_put_nbr((val % pow) / (pow / 10));
        pow = pow / 10;
    }
}

void my_putfloat(double nb, int coma)
{
    int pow = 10;
    long val = 0;

    if (coma == 0) {
        my_put_nbr((int)nb);
        return;
    }
    pow = pow_10(pow, coma);
    val = nb * pow;
    if (val < 0) {
        val *= (-1);
        my_putchar('-');
    }
    if (val % 10 >= 5)
        val = val + (10 - (val % 10));
    display_float(val, pow);
}
