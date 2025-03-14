/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** basic function of the printf function
*/

#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"
#include "../main_functions/my.h"
#include "my_printf.h"

static int is_not_a_flag(const char *format, int i, int y, int v)
{
    if (format[i] == '%' && y == 0) {
        my_putchar('%');
        i += v;
    }
    return i;
}

static int is_in(char *str, char flag)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == flag)
            return 1;
    }
    return 0;
}

static int initialize_flags(const char *format, int i, int v, int *ss_flags)
{
    int a = 0;

    if (is_in("+-0# ", format[i + v]) == 1) {
        ss_flags[0] = format[i + v];
        v++;
    }
    if (is_in("123456789", format[i + v]) == 1) {
        ss_flags[1] = my_getnbr(format + (i + v));
        v += my_intlen(ss_flags[1]);
    }
    if (format[i + v] == '.') {
        v++;
        if (is_in("123456789", format[i + v]) == 1) {
            ss_flags[2] = my_getnbr(format + (i + v));
            v += my_intlen(ss_flags[2]);
        }
    }
    i += v;
    return i;
}

int find_flag(const char *format, int i, va_list list, int *ss_flags)
{
    int j = 0;
    int y = 0;
    int v = 1;
    char *flag = "disc%uboxXfFeEpgGaAn";
    void (*function[20])(va_list, int *) = {&my_number, &my_number, &flag_s,
        &flag_c, &put_modulo, &flag_u, &put_binaries, &flag_o, &flag_x,
        &flag_x_up, &put_float_normal, &put_float_normal, &flag_e, &flag_e_up,
        &flag_p, &flag_g, &flag_g_upper, &flag_n, &flag_n, &flag_n};

    if (format[i] == '%')
        v = initialize_flags(format, i, v, ss_flags) - i;
    for (j = 0; j < 20; j++) {
        if (format[i] == '%' && format[i + v] == flag[j]) {
            function[j](list, ss_flags);
            y++;
            i += v;
        }
    }
    return is_not_a_flag(format, i, y, v);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int j = 0;
    va_list list;
    char *flag = "disc%uboxXfFeEpgGaAn";
    int ss_flags[3] = {0, 0, 0};

    va_start(list, format);
    for (i = 0; format[i] != '\0'; i++) {
        j = find_flag(format, i, list, ss_flags);
        if (i == j)
            my_putchar(format[i]);
        i = j;
    }
    va_end(list);
    return 0;
}
