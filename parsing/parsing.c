/*
** EPITECH PROJECT, 2024
** parsing
** File description:
** parsing
*/

#include "../asm.h"

int is_empty_line(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            return 0;
    }
    return 1;
}

static int parse_h(infos **info_file, int h, char *ref, char *str)
{
    clean_str((*info_file)->big_tab[h][0], " \t");
    if (my_strcmp((*info_file)->big_tab[h][0], ref)) {
        my_printf("asm, %s, line %d: Invalid instruction.\n",
            (*info_file)->file_name, h + 1);
        return 0;
    }
    if (len_tab((*info_file)->big_tab[h]) == 1) {
        my_printf("asm, %s, line %d: No %s specified.\n",
            (*info_file)->file_name, h + 1, str);
        return 0;
    }
    if (!valid_str((*info_file)->big_tab[h][1])) {
        my_printf("asm, %s, line %d: Syntax error.\n",
            (*info_file)->file_name, h + 1);
        return 0;
    }
    return 1;
}

static int parse_header(infos **info_file, int name, int cmt)
{
    if (!parse_h(info_file, name, NAME_CMD_STRING, "name") ||
        !parse_h(info_file, cmt, COMMENT_CMD_STRING, "comment"))
        return 0;
    if (my_strlen((*info_file)->big_tab[name][1]) > PROG_NAME_LENGTH) {
        my_printf("asm: %s: line %d: The program name is too long.",
            (*info_file)->file_name, name + 1);
        return 0;
    }
    if (my_strlen((*info_file)->big_tab[cmt][1]) > COMMENT_LENGTH) {
        my_printf("asm: %s: line %d: The comment is too long.",
            (*info_file)->file_name, cmt + 1);
        return 0;
    }
    return 1;
}

int good_header(infos **info_file)
{
    int name = 0;
    int cmt = 0;

    for (name; (*info_file)->big_tab[name][0][0] == '#' ||
        (*info_file)->big_tab[name][0][0] == ' '; name++);
    for (cmt = name + 1; (*info_file)->big_tab[cmt][0][0] == '#' ||
        (*info_file)->big_tab[cmt][0][0] == ' '; cmt++);
    modify_tab(info_file, name, cmt);
    if (!parse_header(info_file, name, cmt))
        return 0;
    (*info_file)->end_header = cmt + 1;
    return 1;
}

int parsing(infos **info_file, FILE *file)
{
    do_big_tab(info_file, file);
    if (!good_header(info_file))
        return 84;
    if (!find_labels(info_file))
        return 84;
    if (!good_instructions(info_file))
        return 84;
    return 0;
}
