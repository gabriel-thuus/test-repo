/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** header for the function
*/

#include <stdarg.h>

#ifndef MY_PRINTF
    #define MY_PRINTF

int my_printf(const char *format, ...);
void flag_c(va_list list, int *ss_flags);
void put_modulo(va_list list, int *ss_flags);
void my_number(va_list list, int *ss_flags);
void flag_s(va_list list, int *ss_flags);
void flag_u(va_list list, int *ss_flags);
void flag_o(va_list list, int *ss_flags);
void flag_x(va_list list, int *ss_flags);
void flag_x_up(va_list list, int *ss_flags);
void flag_p(va_list list, int *ss_flags);
void put_float_normal(va_list list, int *ss_flags);
void flag_e(va_list list, int *ss_flags);
void flag_e_up(va_list list, int *ss_flags);
void flag_g(va_list list, int *ss_flags);
void flag_g_upper(va_list list, int *ss_flags);
void flag_n(va_list list, int *ss_flags);
void put_binaries(va_list list, int *ss_flags);
void display_width_int(int val, int width, int *ss_flags);
void display_width_float(double val, int coma, int width, char flag);
void display_width_str(char *str, int width);
void print_my_scientific_low(double nb, int coma);
void print_my_scientific_up(double nb, int coma);
void my_put_nbr_base(unsigned int nb, int base);
void binaries(long val);
void print_0(int len, int *ss_flags);
void flag_space_plus(int a, int *ss_flags);
int flag_g_low(double nb);
int flag_g_up(double nb);

#endif
