/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** A function that returns the square root (if it's a whole number)
** of the number given as parameter
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb == 1) {
        return (1);
    }
    while (i <= nb / 2) {
        if (i * i == nb) {
            return i;
        }
        i++;
    }
    return (0);
}
