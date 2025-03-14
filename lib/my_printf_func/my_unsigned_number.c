/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put an unsigned number
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

static int my_put_unsigned_nbr(unsigned int nb)
{
    long big = nb;
    int unite = 0;

    if (big < 10) {
        my_putchar(big + 48);
    } else {
        unite = big % 10;
        big = (big - unite) / 10;
        my_put_nbr(big);
        my_putchar(unite + 48);
    }
}

void flag_u(va_list list, int *ss_flags)
{
    int a = va_arg(list, unsigned int);
    int width = ss_flags[1];
    int len = my_intlen(a);

    if (ss_flags[2] > len)
        width = ss_flags[1] - ss_flags[2] + len;
    if (ss_flags[0] == '-') {
        print_0(len, ss_flags);
        my_put_nbr(a);
        display_width_int(a, width, ss_flags);
    } else {
        if (ss_flags[0] == '+' || ss_flags[0] == ' ')
            width--;
        display_width_int(a, width, ss_flags);
        if (ss_flags[0] == '+' || ss_flags[0] == ' ')
            flag_space_plus(a, ss_flags);
        print_0(len, ss_flags);
        my_put_nbr(a);
    }
}
