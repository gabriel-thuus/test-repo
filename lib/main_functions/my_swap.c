/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** A function that swaps the content of two integers
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
