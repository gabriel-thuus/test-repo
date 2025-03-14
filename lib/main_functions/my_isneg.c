/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** A function that displays either N if the integer passed as parameter
** is negative or P if positive or null
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_isneg(int i)
{
    if (i >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}
