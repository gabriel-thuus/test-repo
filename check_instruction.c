/*
** EPITECH PROJECT, 2024
** check instruction
** File description:
** function bool for instruction
*/

#include "asm.h"

int coding_byte_needed(char *instruction, infos **info_file)
{
    char *instruct[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; instruct[i] != NULL; i++)
        if (!my_strcmp(instruction, instruct[i]))
            return 0;
    return 1;
}

int is_short_direct_value(char *instruction, infos **info_file)
{
    char *instruct[] = {"zjmp", "ldi", "sti", "fork", "lfork", "lldi", NULL};

    for (int i = 0; instruct[i] != NULL; i++)
        if (!my_strcmp(instruction, instruct[i]))
            return 1;
    return 0;
}
