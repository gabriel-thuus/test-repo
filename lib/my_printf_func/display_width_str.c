/*
** EPITECH PROJECT, 2023
** display width of a string
** File description:
** display width of a string
*/

#include <stdlib.h>
#include <stdio.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void display_width_str(char *str, int width)
{
    while (my_strlen(str) < width) {
            my_putchar(' ');
            width -= 1;
    }
}
