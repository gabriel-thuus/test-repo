/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** A function that displays the number given as parameter
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int if_nbr(int v, int nb)
{
    if (v == -2147483648) {
        my_putchar('1' + nb % 10);
    } else {
        my_putchar('0' + nb % 10);
    }
}

int my_put_nbr(int nb)
{
    int v = nb;

    if (nb == -2147483648) {
        nb = nb + 1;
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if_nbr(v, nb);
    return 0;
}
