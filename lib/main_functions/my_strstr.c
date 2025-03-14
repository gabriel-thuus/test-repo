/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** Function strstr
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int j;

    for (i = 0; i < my_strlen(str); i++) {
        for (j = 0; j < my_strlen(to_find)
            && str[i + j] == to_find[j]; j++) {
        }
        if (to_find[j] == '\0') {
            return &str[i];
        }
    }
    return NULL;
}
