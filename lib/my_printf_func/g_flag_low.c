/*
** EPITECH PROJECT, 2023
** gggg
** File description:
** gggg
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

static void display_g(double nb, int i)
{
    if (i <= 6)
        print_my_scientific_low(nb, 6 - (i + 1));
    else
        print_my_scientific_low(nb, 6 - (i - 6));
}

int flag_g_low(double nb)
{
    long val = nb;
    int i = 0;
    int pow = 1;

    if (nb == 0)
        return my_put_nbr(0);
    if (((int)nb < 1000000) && (nb >= 1 || nb <= 0)) {
        for (i = 0; val > 0; i++)
            val = val / 10;
        my_putfloat(nb, 6 - i);
    } else {
        for (i = 0; val % pow_10(pow, 1) == 0; i++) {
            val = nb * pow;
            pow = pow_10(pow, 1);
        }
        display_g(nb, i);
    }
    return 0;
}
