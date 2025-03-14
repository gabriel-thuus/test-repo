/*
** EPITECH PROJECT, 2024
** usage
** File description:
** usage
*/

#include "asm.h"

int usage(void)
{
    write(1, "USAGE\n", 7);
    write(1, "./asm file_name[.s]\n", 21);
    write(1, "DESCRIPTION\n", 13);
    write(1, "file_name file in assembly language to be converted into\n", 58);
    write(1, " file_name.cor, an executable in the Virtual Machine.\n", 55);
    return 0;
}
