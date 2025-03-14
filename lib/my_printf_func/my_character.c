/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put a string
*/

#include <stdarg.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void flag_c(va_list list, int *ss_flags)
{
    int a = va_arg(list, int);

    if (ss_flags[0] == '-') {
        my_putchar(a);
        for (int i = 1; i < ss_flags[1]; i++)
            my_putchar(' ');
    } else {
        for (int i = 1; i < ss_flags[1]; i++)
            my_putchar(' ');
        my_putchar(a);
    }
}
