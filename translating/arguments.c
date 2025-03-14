/*
** EPITECH PROJECT, 2024
** arguments
** File description:
** arguments
*/

#include "../asm.h"



static void type_of_arg(infos **info_file, char **line, int i)
{
    (*info_file)->instr[(*info_file)->idx].val = malloc(sizeof(val_t));
    if (line[i][0] == LABEL_CHAR) {
        (*info_file)->instr[(*info_file)->idx].is_label = true;
        (*info_file)->instr[(*info_file)->idx].label = line[i] + 1;
        (*info_file)->instr[(*info_file)->idx].val->val = 0;
        return;
    } else if (line[i][1] == LABEL_CHAR) {
        (*info_file)->instr[(*info_file)->idx].is_label = true;
        (*info_file)->instr[(*info_file)->idx].label = line[i] + 2;
        (*info_file)->instr[(*info_file)->idx].val->val = 0;
        return;
    }
    if (line[i][0] == DIRECT_CHAR) {
        (*info_file)->instr[(*info_file)->idx].val->val =
            my_getnbr(line[i] + 1);
    } else
        (*info_file)->instr[(*info_file)->idx].val->val =
            my_getnbr(line[i]);
}

void write_args(
    infos **info_file, FILE *file_cor, char **tab, int begin)
{
    char **line = tab + begin;
    int len = len_tab(line);
    unsigned int reg = 0;
    unsigned int size = 0;

    for (int i = 1; line[i]; i++) {
        if (line[i][0] == '#')
            break;
        reg = recognize_register(info_file, line[i], line[0]);
        size = arg_size(reg, line[0], info_file);
        type_of_arg(info_file, line, i);
        if ((*info_file)->instr[(*info_file)->idx].is_label == true)
            (*info_file)->instr[(*info_file)->idx].size = 2;
        else
            (*info_file)->instr[(*info_file)->idx].size = size;
        (*info_file)->size += size;
        (*info_file)->idx++;
    }
}
