/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put a number
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void print_0(int len, int *ss_flags)
{
    while (len < ss_flags[2]) {
        my_putchar('0');
        len++;
    }
}

void flag_space_plus(int a, int *ss_flags)
{
    if (a > 0) {
        if (ss_flags[0] == '+')
            my_putchar('+');
        if (ss_flags[0] == ' ')
            my_putchar(' ');
    }
}

void my_number(va_list list, int *ss_flags)
{
    int a = va_arg(list, int);
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
