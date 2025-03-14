/*
** EPITECH PROJECT, 2023
** put binaries
** File description:
** flag b
*/

#include <stdarg.h>
#include "../main_functions/my.h"
#include "my_printf.h"

void put_binaries(va_list list, int *ss_flags)
{
    binaries(va_arg(list, long));
}
