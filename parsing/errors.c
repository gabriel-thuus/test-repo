/*
** EPITECH PROJECT, 2024
** errors
** File description:
** errors
*/

#include "../asm.h"

static int invalid_arg(infos **info_file, int i, int v)
{
    if (v == 84) {
        my_printf("asm, %s, line %d: Invalid instruction.\n",
            (*info_file)->file_name, i + 1);
        return 0;
    }
    if (v == 86) {
        my_printf("asm, %s, line %d: Invalid register number.\n",
            (*info_file)->file_name, i + 1);
        return 0;
    }
    return 1;
}

int error_cases(infos **info_file, int i, int v)
{
    if (v == 0) {
        my_printf("asm, %s, line %d: ",
            (*info_file)->file_name, i + 1);
        my_printf("The argument given to the instruction is invalid.\n");
        return 0;
    }
    if (v == 85) {
        my_printf("asm, %s, line %d: Undefined label.\n",
            (*info_file)->file_name, i + 1);
        return 0;
    }
    if (v == 87) {
        my_printf("asm, %s, line %d: ",
            (*info_file)->file_name, i + 1);
        my_printf("Too many arguments given to the instruction.\n");
        return 0;
    }
    return invalid_arg(info_file, i, v);
}
