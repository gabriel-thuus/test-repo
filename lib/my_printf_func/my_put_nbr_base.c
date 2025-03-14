/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_put_nbr_base
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

static int put_diese(int len)
{
    my_putchar('0');
    len++;
    return len;
}

void my_put_nbr_base(unsigned int nb, int base)
{
    int reste = nb % base;
    int quotient = (nb - reste) / base;
    char *d = "0123456789abcdef";

    if (nb > base)
        my_put_nbr_base(quotient, base);
    my_putchar(d[reste]);
}

void flag_o(va_list list, int *ss_flags)
{
    int a = va_arg(list, unsigned int);
    int width = ss_flags[1];
    int len = my_intlen(a);

    if (ss_flags[2] > len)
        width = ss_flags[1] - ss_flags[2] + len;
    if (ss_flags[0] == '-') {
        print_0(len, ss_flags);
        my_put_nbr_base(a, 8);
        display_width_int(a, width, ss_flags);
    } else {
        if (ss_flags[0] == '#' && ss_flags[2] < len + 1)
            width--;
        display_width_int(a, width, ss_flags);
        if (ss_flags[0] == '#') {
            len = put_diese(len);
        }
        print_0(len, ss_flags);
        my_put_nbr_base(a, 8);
    }
}

void flag_x(va_list list, int *ss_flags)
{
    if (ss_flags[0] == '#')
        my_putstr("0x");
    my_put_nbr_base(va_arg(list, unsigned int), 16);
}
