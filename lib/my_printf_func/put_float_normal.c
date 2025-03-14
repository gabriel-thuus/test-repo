/*
** EPITECH PROJECT, 2023
** put_float
** File description:
** function for flag f
*/

#include <stdarg.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void put_float_normal(va_list list, int *ss_flags)
{
    double a = va_arg(list, double);

    if (a > 0) {
        if (ss_flags[0] == '+')
            my_putchar('+');
        if (ss_flags[0] == ' ')
            my_putchar(' ');
    }
    if (ss_flags[2] != 0)
        my_putfloat(a, ss_flags[2]);
    else
        my_putfloat(a, 6);
}
