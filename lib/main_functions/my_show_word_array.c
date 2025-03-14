/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** A function that displays all the strings
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_show_word_array(char const **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
