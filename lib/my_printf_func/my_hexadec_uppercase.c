/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put an hexadecimal in uppercase
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

static void find_hexadec(unsigned int nb)
{
    int reste = nb % 16;
    int quotient = (nb - reste) / 16;
    char *d = "0123456789ABCDEF";

    if (nb > 16)
        find_hexadec(quotient);
    my_putchar(d[reste]);
}

void flag_x_up(va_list list, int *ss_flags)
{
    if (ss_flags[0] == '#')
        my_putstr("0X");
    find_hexadec(va_arg(list, unsigned int));
}
