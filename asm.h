/*
** EPITECH PROJECT, 2024
** asm
** File description:
** header
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "lib/include/my.h"
#include "lib/include/my_printf.h"
#include "B-CPE-200_op/op.h"
#include <sys/stat.h>
#include <fcntl.h>

typedef struct val_s {
    unsigned int val;
} val_t;

typedef struct label_s {
    unsigned int adress;
    char *label;
} label_t;

typedef struct instruction_s {
    int instruction;
    unsigned int coding_byte;
    val_t *val;
    unsigned int size;
    bool is_label;
    char *label;
    label_t *label_adress;
    unsigned int id_line;
} instruction_t;

typedef struct infos_t {
    char *file_name;
    char **labels;
    char ***big_tab;
    int end_header;
    bool useful;
    int prog_size;
    instruction_t *instr;
    int length_instr;
    unsigned short size;
    int idx;
} infos;

#ifndef ASM
    #define ASM

unsigned int big_endian(unsigned int value, int ref);

void mine_strncpy(char *dest, char *src, int nb);
int is_in(char c);
int is_valid(char *str);
int valid_str(char *str);
int is_empty_line(char *str);

void free_tab(char **tab);
int len_tab(char **tab);
void modify_tab(infos **info_file, int idx_name, int idx_cmt);
void do_big_tab(infos **info_file, FILE *file);

int coding_byte_needed(char *instruction, infos **info_file);
int is_short_direct_value(char *instruction, infos **info_file);

// Parsing
int error_cases(infos **info_file, int i, int v);
int good_header(infos **info_file);
int parsing(infos **info_file, FILE *file);
int find_labels(infos **info_file);
int is_label(infos **info_file, char *str);
int recognize_register(infos **info_file, char *str, char *instruction);
int good_instructions(infos **info_file);

// Translating
instruction_t *initialize_tab(int count);
void head(infos **info_file, FILE *file_cor);
int arg_size(int reg, char *line, infos **info_file);
void put_coding_byte(infos **info_file, char **tab, int i, int begin);
void instructions(infos **info_file, FILE *file_cor);
void write_args(
    infos **info_file, FILE *file_cor, char **tab, int begin);
void write_label(infos **info_file, FILE *file_cor);
void fwrite_instructions(infos **info_file, FILE *file_cor);

int usage(void);
int wrong_file(int ac, char **av);
int main(int ac, char **av);

#endif /* !ASM */
