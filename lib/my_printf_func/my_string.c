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

static void my_putstrn(char *str, int *ss_flags)
{
    for (int i = 0; i < ss_flags[2]; i++)
        my_putchar(str[i]);
}

void flag_s(va_list list, int *ss_flags)
{
    char *a = va_arg(list, char *);
    int width = ss_flags[1];

    if (ss_flags[0] == '-') {
        if (ss_flags[2] != 0) {
            my_putstrn(a, ss_flags);
            display_width_str(a, width + (my_strlen(a) - ss_flags[2]));
        } else {
            my_putstr(a);
            display_width_str(a, width + (my_strlen(a) - ss_flags[2]));
        }
    } else {
        if (ss_flags[2] != 0) {
            display_width_str(a, width + (my_strlen(a) - ss_flags[2]));
            my_putstrn(a, ss_flags);
        } else {
            display_width_str(a, width);
            my_putstr(a);
        }
    }
}
