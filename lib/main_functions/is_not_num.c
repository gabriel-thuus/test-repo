/*
** EPITECH PROJECT, 2023
** is_alpha.c
** File description:
** function that check if c is a num
*/

int is_not_num(char c)
{
    if (c < '0' || c > '9')
        return 1;
    return 0;
}
