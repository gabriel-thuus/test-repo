##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## A makefile that compile your libmy with ur .c
##

SRC	=	main.c	\
		usage.c	\
		parsing/errors.c	\
		parsing/parsing.c	\
		parsing/labels.c	\
		parsing/instructions.c	\
		translating/head.c	\
		translating/instructions.c	\
		translating/coding_byte.c	\
		translating/arguments.c	\
		translating/writing.c	\
		translating/label_adress.c	\
		check_instruction.c	\
		valid_str.c	\
		transform_tab.c	\
		do_big_tab.c	\
		B-CPE-200_op/op.c	\

OBJ = $(SRC:.c=.o)

CFLAGS = -g

MYLIB = -L./lib/ -lmy

NAME = asm

all : $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/
	gcc -o $(NAME) $(SRC) -g $(MYLIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C ./lib/ fclean

re: fclean all

.PHONY: re fclean clean all
