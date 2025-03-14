/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** A function that returns 1 if the number is prime
** and 0 if not
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_is_prime(int nb)
{
    int i;
    int v = 0;

    if (nb <= 0 || nb == 1) {
        return (0);
    }
    for (i = 1; i <= nb; i++) {
            if (nb % i == 0) {
                v++;
            }
        }
    if (v > 2) {
        return (0);
    } else {
        return (1);
    }
}
