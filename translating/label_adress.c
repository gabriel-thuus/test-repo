/*
** EPITECH PROJECT, 2024
** find the address of labels
** File description:
** labels
*/

#include "../asm.h"

static void calcul(instruction_t *instr, int i, int *distance)
{
    if (instr[i].instruction != -1 ||
        instr[i].coding_byte != -1)
        *distance += 1;
    if (instr[i].size != 0)
        *distance += instr[i].size;
}

static int calcul_distance(instruction_t *instr, int begin, int arrival)
{
    int distance = 0;

    if (instr[begin].id_line == instr[arrival].id_line &&
        (begin - 1) == arrival)
        return distance;
    if (begin <= arrival) {
        for (int i = begin; i < arrival; i++)
            calcul(instr, i, &distance);
    } else {
        for (int i = begin; i > arrival; i--)
            calcul(instr, i, &distance);
        distance = 65535 - distance + 2;
    }
    return distance;
}

static void find_adress_label(
    infos **info_file, instruction_t *instr, int i, int actual_instr)
{
    int j = 0;
    char *label = NULL;

    for (j = 0; j < (*info_file)->idx; j++) {
        label = my_strcat(my_strdup(instr[i].label), my_strdup(":"));
        if (instr[j].label_adress &&
            !my_strcmp(instr[j].label_adress->label, label)) {
            instr[i].val->val = calcul_distance(instr, actual_instr, j);
        }
        free(label);
    }
}

void write_label(infos **info_file, FILE *file_cor)
{
    instruction_t *instr = (*info_file)->instr;
    int actual_instr = 0;

    if (!(*info_file)->labels)
        return;
    for (int i = 0; i < (*info_file)->idx; i++) {
        if (instr[i].instruction != -1)
            actual_instr = i;
        if (instr[i].is_label == true)
            find_adress_label(info_file, instr, i, actual_instr);
    }
}
