/*
** EPITECH PROJECT, 2023
** gggg
** File description:
** gggg
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void flag_g(va_list list, int *ss_flags)
{
    double a = va_arg(list, double);

    if (a > 0) {
        if (ss_flags[0] == '+')
            my_putchar('+');
        if (ss_flags[0] == ' ')
            my_putchar(' ');
    }
    flag_g_low(a);
}
