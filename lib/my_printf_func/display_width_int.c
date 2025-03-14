/*
** EPITECH PROJECT, 2023
** display width of an int
** File description:
** display int of an int
*/

#include <stdlib.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

static int display_if_0(int nb_char, int *ss_flags, int width)
{
    if (nb_char > ss_flags[2] && ss_flags[2] != 0) {
        my_putchar(' ');
        nb_char -= 1;
        width -= 1;
    } else {
        my_putchar('0');
        width -= 1;
    }
    return width;
}

void display_width_int(int val, int width, int *ss_flags)
{
    int nb_char = ss_flags[1];

    while (my_intlen(val) < width) {
        if (ss_flags[0] == '0') {
            width = display_if_0(nb_char, ss_flags, width);
        } else {
            my_putchar(' ');
            width -= 1;
        }
    }
}
