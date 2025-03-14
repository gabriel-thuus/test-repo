/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** A function that return the smallest prime number that is
** greater than, or equal to, the number given as parameter
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1) {
        return nb;
    }
    while (my_is_prime(nb) != 1) {
        nb = nb + 1;
    }
    return nb;
}
