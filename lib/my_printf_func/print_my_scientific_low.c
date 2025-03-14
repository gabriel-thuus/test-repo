/*
** EPITECH PROJECT, 2023
** print scientific float
** File description:
** a function that print scientific float
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../main_functions/my.h"
#include "my_printf.h"

static int pow_10(int pow, int coma)
{
    for (int i = 0; i < coma; i++)
        pow *= 10;
    return pow;
}

static void display_scientific_float(long nb_int, int pow, int i, int coma)
{
    my_put_nbr(nb_int / pow);
    if (coma > 0) {
        my_putchar('.');
        for (int j = 0; j < coma; j++) {
            my_put_nbr(((nb_int % pow) / (pow / 10)));
            pow = pow / 10;
        }
    }
    my_putstr("e+");
    if (i <= 9)
        my_put_nbr(0);
    my_put_nbr(i);
}

static void print_scientific_if_not_in_0_and_1(double nb, long val, int coma)
{
    long nb_int = 0;
    int pow = 10;
    int i = 0;

    for (i = 0; val > 9; i++)
        val = val / 10;
    pow = pow_10(pow, coma);
    nb_int = (nb * pow) / pow_10(1, i);
    if (nb_int < 0) {
        nb_int *= -1;
    }
    if (nb_int % 10 >= 5)
        nb_int = nb_int + (10 - (nb_int % 10));
    if (nb_int / pow == 10) {
        nb_int = nb_int / 10;
        i++;
    }
    display_scientific_float(nb_int, pow, i, coma);
}

static void print_scientific_if_in_0_and_1(double nb, long val, int coma)
{
    int i = 0;

    if (nb == 0) {
        write(1, "0.000000e+00", 13);
        return;
    }
    for (i = 0; val == 0; i++) {
        nb *= 10;
        val = nb;
    }
    my_putfloat(nb, coma);
    my_putstr("e-");
    if (i <= 9)
        my_put_nbr(0);
    my_put_nbr(i);
    return;
}

void print_my_scientific_low(double nb, int coma)
{
    long val = nb;

    if (val < 0) {
        val *= -1;
        my_putchar('-');
    }
    if (val != 0)
        print_scientific_if_not_in_0_and_1(nb, val, coma);
    if (val == 0)
        print_scientific_if_in_0_and_1(nb, val, coma);
}
