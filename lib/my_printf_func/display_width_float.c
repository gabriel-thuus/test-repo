/*
** EPITECH PROJECT, 2023
** display width of a float
** File description:
** display width of a float
*/

#include <stdlib.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void display_width_float(double val, int coma, int width, char flag)
{
    while (my_floatlen(val, coma) < width) {
        if (flag == '0') {
            my_putchar('0');
            width -= 1;
        } else {
            my_putchar(' ');
            width -= 1;
        }
    }
    return;
}
