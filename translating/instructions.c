/*
** EPITECH PROJECT, 2024
** instruction
** File description:
** instructions
*/

#include "../asm.h"

static void write_instruction(
    infos **info_file, FILE *file_cor, char **tab, int begin)
{
    for (int i = 0; i < 16; i++) {
        if (!my_strcmp(tab[begin], op_tab[i].mnemonique)) {
            (*info_file)->instr[(*info_file)->idx].instruction =
                op_tab[i].code;
            (*info_file)->idx++;
            (*info_file)->size += 1;
            put_coding_byte(info_file, tab, i, begin);
            write_args(info_file, file_cor, tab, begin);
        }
    }
}

static void get_label(infos **info_file, char ***tab, int i)
{
    (*info_file)->instr[(*info_file)->idx].label_adress =
        malloc(sizeof(label_t));
    (*info_file)->instr[(*info_file)->idx].label_adress->label =
        tab[i][0];
    (*info_file)->idx++;
}

static void label_checker(
    infos **info_file, char ***tab, int i, FILE *file_cor)
{
    if (is_label(info_file, tab[i][0]) && len_tab(tab[i]) == 1) {
        get_label(info_file, tab, i);
        return;
    } else if (is_label(info_file, tab[i][0]) &&
        len_tab(tab[i]) > 1 && tab[i][1][0] == '#') {
        get_label(info_file, tab, i);
        return;
    }
    if (is_label(info_file, tab[i][0])) {
        get_label(info_file, tab, i);
        write_instruction(info_file, file_cor, tab[i], 1);
    } else
        write_instruction(info_file, file_cor, tab[i], 0);
}

static void create_struct_args(infos **info_file, char ***tab)
{
    unsigned int count = 0;

    for (int i = (*info_file)->end_header; tab[i]; i++) {
        if (tab[i][0][0] == '#' || tab[i][0][0] == ' ')
            continue;
        count += len_tab(tab[i]) + 1;
    }
    (*info_file)->length_instr = count;
    (*info_file)->instr = initialize_tab(count);
}

void instructions(infos **info_file, FILE *file_cor)
{
    char ***tab = (*info_file)->big_tab;
    unsigned int idx = (*info_file)->idx;
    int v = 0;

    create_struct_args(info_file, tab);
    for (int i = (*info_file)->end_header; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != NULL; j++) {
            (*info_file)->instr[v].id_line = i;
            v++;
        }
        if (tab[i][0][0] == '#' || tab[i][0][0] == ' ')
            continue;
        label_checker(info_file, tab, i, file_cor);
    }
}
