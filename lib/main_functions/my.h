/*
** EPITECH PROJECT, 2023
** my function
** File description:
** An header file that contains the prototypes of
** all the function exposed by your libmy.a
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
void my_strncpy(char **dest, char *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char const **tab);
char **my_str_to_word_array(char const *str, char *ref);
char *my_strdup(char const *src);
int my_intlen(long nb);
int my_floatlen(double nb, int coma);
void my_putfloat(double nb, int coma);
int is_not_num(char c);
char *my_strdup(char const *src);
char *load_file_in_mem(char const *filepath);
int is_digit(char *args);
char **my_tabdup(char **env);
void clean_str(char *str, char *separators);
char *my_atoi(int nb);
int is_alpha(char c);
int str_is_alpha(char *str);

#endif
