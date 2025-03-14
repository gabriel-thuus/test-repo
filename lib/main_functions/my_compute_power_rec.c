/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** A recursive function that returns the first
** argument raised to the power p
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int v = nb;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p > 0) {
        return (v * my_compute_power_rec(nb, p - 1));
    }
}
