/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_put_nbr_base
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"

static void my_hexa(unsigned long nb)
{
    unsigned int reste = nb % 16;
    unsigned long quotient = (nb - reste) / 16;
    char *d = "0123456789abcdef";

    if (nb > 16)
        my_hexa(quotient);
    my_putchar(d[reste]);
}

void flag_p(va_list list, int *ss_flags)
{
    unsigned long a = va_arg(list, unsigned long);

    if (a > 0) {
        if (ss_flags[0] == '+')
            my_putchar('+');
        if (ss_flags[0] == ' ')
            my_putchar(' ');
    }
    my_putstr("0x");
    my_hexa(a);
}
