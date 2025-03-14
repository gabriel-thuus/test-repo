/*
** EPITECH PROJECT, 2024
** writing
** File description:
** writing
*/

#include "../asm.h"

void fwrite_instructions(infos **info_file, FILE *file_cor)
{
    instruction_t *instr = (*info_file)->instr;
    int v = 0;
    int a = 0;

    for (int i = 0; i < (*info_file)->idx; i++) {
        if (instr[i].instruction != -1)
            fwrite(&instr[i].instruction, 1, 1, file_cor);
        if (instr[i].coding_byte != -1)
            fwrite(&instr[i].coding_byte, 1, 1, file_cor);
        if (instr[i].val && instr[i].is_label == false) {
            instr[i].val->val = big_endian(instr[i].val->val, instr[i].size);
            fwrite(&instr[i].val->val, instr[i].size, 1, file_cor);
            continue;
        }
        if (instr[i].is_label == true) {
            instr[i].val->val = big_endian(instr[i].val->val, instr[i].size);
            fwrite(&instr[i].val->val, instr[i].size, 1, file_cor);
        }
    }
}
