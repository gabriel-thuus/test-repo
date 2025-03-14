/*
** EPITECH PROJECT, 2024
** translating header
** File description:
** translate header
*/

#include "../asm.h"

#include <stdint.h>

unsigned int big_endian(unsigned int value, int ref)
{
    unsigned int val = 0;

    if (ref == 1)
        return value;
    if (ref == 2) {
        val = ((value >> 8) & 0x00FF) |
            ((value << 8) & 0xFF00);
    }
    if (ref == 4) {
        val = ((value >> 24) & 0x000000FF) |
            ((value >> 8) & 0x0000FF00) |
            ((value << 8) & 0x00FF0000) |
            ((value << 24) & 0xFF000000);
    }
    return val;
}

instruction_t *initialize_tab(int count)
{
    instruction_t *instr = malloc(sizeof(instruction_t) * count);

    for (int i = 0; i < count; i++) {
        instr[i].coding_byte = -1;
        instr[i].instruction = -1;
        instr[i].is_label = false;
        instr[i].label = NULL;
        instr[i].label_adress = NULL;
        instr[i].size = 0;
        instr[i].val = NULL;
        instr[i].id_line = -1;
    }
    return instr;
}

static char *get_str(char *str, char delim)
{
    int begin = 0;
    int arrival = 0;
    char *new_str = NULL;
    int v = 0;

    for (begin; str[begin] != delim; begin++);
    arrival = begin + 1;
    for (arrival; str[arrival] != delim; arrival++);
    begin += 1;
    new_str = malloc(sizeof(char) * (arrival - begin + 1));
    for (begin; begin != arrival; begin++) {
        new_str[v] = str[begin];
        v++;
    }
    new_str[v] = '\0';
    return new_str;
}

void head(infos **info_file, FILE *file_cor)
{
    header_t head = {0};
    char ***tab = (*info_file)->big_tab;
    int i = 0;
    char *str = NULL;

    (*info_file)->idx = 0;
    (*info_file)->size = 0;
    instructions(info_file, file_cor);
    write_label(info_file, file_cor);
    head.magic = big_endian(COREWAR_EXEC_MAGIC, 4);
    head.prog_size = big_endian((*info_file)->size, 4);
    for (i; my_strcmp(tab[i][0], ".name"); i++);
    my_strcpy(head.prog_name, get_str(tab[i][1], '"'));
    for (i; my_strcmp(tab[i][0], ".comment"); i++);
    my_strcpy(head.comment, get_str(tab[i][1], '"'));
    fwrite(&head, sizeof(header_t), 1, file_cor);
    fwrite_instructions(info_file, file_cor);
}
