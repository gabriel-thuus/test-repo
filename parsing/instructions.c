/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** check instructions
*/

#include "../asm.h"

static void short_or_full_value(char *instruction, infos **info_file)
{
    if (!is_short_direct_value(instruction, info_file))
        (*info_file)->prog_size += DIR_SIZE;
    else
        (*info_file)->prog_size += IND_SIZE;
}

static int recognize_register2(infos **info_file, char *str, char *instruction)
{
    if (str[0] == DIRECT_CHAR) {
        if ((str[1] == LABEL_CHAR && is_label(info_file, str + 2)) ||
            is_digit(str + 1)) {
            short_or_full_value(instruction, info_file);
            return T_DIR;
        }
        if (str[1] == LABEL_CHAR && !is_label(info_file, str + 2))
            return 85;
    }
    if ((str[0] == LABEL_CHAR && is_label(info_file, str + 1)) ||
        is_digit(str)) {
        (*info_file)->prog_size += IND_SIZE;
        return T_IND;
    } else if (str[0] == LABEL_CHAR && !is_label(info_file, str + 2))
            return 85;
    return 0;
}

int recognize_register(infos **info_file, char *str, char *instruction)
{
    if (str[0] == 'r' && is_digit(str + 1)) {
        if (my_getnbr(str + 1) >= 1 && my_getnbr(str + 1) <= 16) {
            (*info_file)->prog_size += 1;
            return T_REG;
        } else
            return 86;
    } else if (str[0] == 'r')
        return 86;
    return recognize_register2(info_file, str, instruction);
}

static int valid_params(infos **info_file, char **tab, int i, int begin)
{
    int reg = 0;
    int nb_args = op_tab[i].nbr_args + 1 + begin;

    if (len_tab(tab) != nb_args && tab[nb_args][0] != '#')
        return 0;
    for (int j = begin + 1; j < nb_args; j++) {
        clean_str(tab[j], ",");
        reg = recognize_register(info_file, tab[j], tab[begin]);
        if (reg == 85)
            return 85;
        if (reg == 86)
            return 86;
        if (reg > 0 && (reg & op_tab[i].type[j - 1 - begin]));
        else
            return 0;
    }
    return 1;
}

static int return_value(int v)
{
    if (v == 0)
        return 0;
    if (v == 85)
        return 85;
    if (v == 86)
        return 86;
    return 1;
}

static int valid_instruction(infos **info_file, char **tab, int i, int begin)
{
    int v = 0;
    int nb_args = 0;

    clean_str(tab[begin], " \t");
    if (!my_strcmp(tab[begin], op_tab[i].mnemonique)) {
        if (coding_byte_needed(tab[begin], info_file))
            (*info_file)->prog_size += 1;
        nb_args = len_tab(tab) - (1 + begin);
        if (nb_args > op_tab[i].nbr_args &&
            tab[op_tab[i].nbr_args + 1][0] != '#')
            return 87;
        v = valid_params(info_file, tab, i, begin);
        if (return_value(v) != 1)
            return return_value(v);
        (*info_file)->useful = true;
        (*info_file)->prog_size += 1;
    }
    return 1;
}

static int is_an_instruction(infos **info_file, char **tab, int begin)
{
    int v = 0;

    (*info_file)->useful = false;
    for (int i = 0; i < 16; i++) {
        v = valid_instruction(info_file, tab, i, begin);
        if (v == 0)
            return 0;
        if (v == 85)
            return 85;
        if (v == 86)
            return 86;
        if (v == 87)
            return 87;
    }
    if ((*info_file)->useful == false)
        return 84;
    return 1;
}

static int call_is_an_instruction(infos **info_file, int i)
{
    int v = 0;

    if ((*info_file)->labels &&
        is_label(info_file, (*info_file)->big_tab[i][0]) &&
        len_tab((*info_file)->big_tab[i]) == 1)
        return 1;
    if ((*info_file)->labels &&
        is_label(info_file, (*info_file)->big_tab[i][0])) {
        v = is_an_instruction(info_file, (*info_file)->big_tab[i], 1);
    } else {
        v = is_an_instruction(info_file, (*info_file)->big_tab[i], 0);
    }
    return v;
}

int good_instructions(infos **info_file)
{
    int i = (*info_file)->end_header;
    int v = 0;

    for (i; (*info_file)->big_tab[i] != NULL; i++) {
        if ((*info_file)->big_tab[i][0][0] == '#' ||
            (*info_file)->big_tab[i][0][0] == ' ')
            continue;
        v = call_is_an_instruction(info_file, i);
        if (!error_cases(info_file, i, v))
            return 0;
    }
    return 1;
}
