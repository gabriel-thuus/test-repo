/*
** EPITECH PROJECT, 2024
** coding byte
** File description:
** coding byte
*/

#include "../asm.h"

static int is_dir_size(int *reg)
{
    if (*reg == DIR_SIZE)
        *reg -= 1;
}

int arg_size(int reg, char *line, infos **info_file)
{
    int size = 1;

    if (reg == T_DIR && is_short_direct_value(line, info_file))
        size = IND_SIZE;
    else if (reg == T_DIR)
        size = DIR_SIZE;
    if (reg == T_IND)
        size = IND_SIZE;
    return size;
}

static int get_instr_length(char **tab)
{
    int len = 0;

    for (len; tab[len] && tab[len][0] != '#'; len++);
    return len;
}

static uint8_t calcul_coding_byte(
    infos **info_file, char **line, op_t *op_l, int begin)
{
    uint8_t val = 0;
    char **tab = line + begin;
    int len = get_instr_length(tab);
    int reg = 0;

    if (op_l->nbr_args == 1) {
        reg = recognize_register(info_file, tab[1], tab[0]);
        val = (reg << 6) | val;
    }
    if (op_l->nbr_args >= 2) {
        for (int i = 1; i < len; i++) {
            reg = recognize_register(info_file, tab[i], tab[0]);
            is_dir_size(&reg);
            val = (reg << (6 - ((i - 1) * 2))) | val;
        }
    }
    return val;
}

void put_coding_byte(infos **info_file, char **tab, int i, int begin)
{
    if (coding_byte_needed(op_tab[i].mnemonique, info_file)) {
        (*info_file)->instr[(*info_file)->idx].coding_byte =
            calcul_coding_byte(info_file, tab, &op_tab[i], begin);
        (*info_file)->idx++;
        (*info_file)->size += 1;
    }
}
