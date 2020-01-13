# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rverscho <rverscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/02 19:12:32 by rverscho       #+#    #+#                 #
#    Updated: 2020/01/13 17:06:08 by rverscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = empty_flags.c fill_struct_to_write_hex.c fill_struct_to_write_int.c \
	fill_struct_to_write_str.c functions.c make_char.c make_numbers.c \
	ft_printf.c main_flag_handeler.c string_check.c \
	set_1_0_for_int.c set_1_0_for_str.c utils.c utils2.c utils3.c get_len.c \
	

BONUS = empty_flags.o ft_functions.o ft_main_flag_handeler.o \
	ft_make_c.o ft_make_d.o ft_make_i.o ft_make_p.o \
	ft_make_s.o ft_make_u.o ft_make_x.o ft_make_Xx.o ft_printf.o utils.o \
	width_handler_num_left.o width_handler_num_spacing.o width_handler_num.o \
	width_handler_str_left.o width_handler_str_prec.o width_handler_str.o width_handler_num_zero.o

O_FILES := $(SRC:.c=.o)
BO_FILES := $(BONUS:.c=.o)
CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

bonus: $(NAME) $(BO_FILES)
	ar rc $(NAME) $(BO_FILES)

%.o: %.c
	$(CC) -c $? -o $@

clean:
	/bin/rm -f $(O_FILES) $(BO_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

gcc:
	gcc $(SRC) test.c -g
	./a.out