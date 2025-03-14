##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A makefile that compiles your libmy
##

SRC	=	main_functions/my_compute_power_rec.c	\
		main_functions/my_compute_square_root.c	\
		main_functions/my_find_prime_sup.c	\
		main_functions/my_getnbr.c	\
		main_functions/my_isneg.c	\
		main_functions/my_is_prime.c	\
		main_functions/my_putchar.c	\
		main_functions/my_put_nbr.c	\
		main_functions/my_putstr.c	\
		main_functions/my_revstr.c	\
		main_functions/my_show_word_array.c	\
		main_functions/my_strcmp.c	\
		main_functions/my_strcpy.c	\
		main_functions/my_strlen.c	\
		main_functions/my_strcat.c	\
		main_functions/my_strncat.c	\
		main_functions/my_strncmp.c	\
		main_functions/my_strncpy.c	\
		main_functions/my_strstr.c	\
		main_functions/my_str_to_word_array.c	\
		main_functions/my_swap.c	\
		main_functions/my_intlen.c	\
		main_functions/my_floatlen.c	\
		main_functions/my_putfloat.c	\
		main_functions/is_not_num.c	\
		main_functions/my_strdup.c	\
		main_functions/is_digit.c	\
		main_functions/load_file_in_mem.c	\
		main_functions/my_tabdup.c	\
		main_functions/clean_str.c	\
		main_functions/my_atoi.c	\
		main_functions/str_is_alpha.c	\
		my_printf_func/display_width_float.c	\
		my_printf_func/display_width_int.c	\
		my_printf_func/display_width_str.c	\
		my_printf_func/flag_n.c	\
		my_printf_func/g_flag_low.c	\
		my_printf_func/g_flag_up.c	\
		my_printf_func/my_character.c	\
		my_printf_func/my_hexadec_uppercase.c	\
		my_printf_func/my_number.c	\
		my_printf_func/my_printf.c	\
		my_printf_func/my_put_nbr_base.c	\
		my_printf_func/my_scientific_low.c	\
		my_printf_func/my_scientific_up.c	\
		my_printf_func/my_string.c	\
		my_printf_func/my_unsigned_number.c	\
		my_printf_func/print_my_scientific_low.c	\
		my_printf_func/print_my_scientific_up.c	\
		my_printf_func/put_float_normal.c	\
		my_printf_func/put_gflag_low.c	\
		my_printf_func/put_gflag_up.c	\
		my_printf_func/put_modulo.c	\
		my_printf_func/put_binaries.c	\
		my_printf_func/binaries.c	\
		my_printf_func/my_put_adress.c	\

OBJ =	$(SRC:.c=.o)

NAME = libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
