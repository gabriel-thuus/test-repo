/*
** EPITECH PROJECT, 2023
** binarie
** File description:
** flag b
*/

#include "../main_functions/my.h"
#include "my_printf.h"

void binaries(long val)
{
    if (val == 0)
        return;
    binaries(val / 2);
    if (val % 2 == 0)
        my_put_nbr(0);
    if (val % 2 == 1)
        my_put_nbr(1);
}
