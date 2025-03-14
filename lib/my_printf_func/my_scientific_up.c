/*
** EPITECH PROJECT, 2023
** my_scientific_LOW
** File description:
** return scientific notation in LOWERCASE
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void flag_e_up(va_list list, int *ss_flags)
{
    double a = va_arg(list, double);

    if (a > 0) {
        if (ss_flags[0] == '+')
            my_putchar('+');
        if (ss_flags[0] == ' ')
            my_putchar(' ');
    }
    print_my_scientific_up(a, 6);
}
