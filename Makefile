# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rverscho <rverscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/02 19:12:32 by rverscho       #+#    #+#                 #
#    Updated: 2019/12/21 19:04:37 by rverscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = empty_flags.c ft_functions.c ft_main_flag_handeler.c \
	ft_make_c.c ft_make_d.c ft_make_i.c ft_make_p.c \
	ft_make_s.c ft_make_u.c ft_make_x.c ft_make_Xx.c ft_printf.c utils.c \
	width_handeler.c

BONUS = empty_flags.o ft_functions.o ft_main_flag_handeler.o \
	ft_make_c.o ft_make_d.o ft_make_i.o ft_make_p.o \
	ft_make_s.o ft_make_u.o ft_make_x.o ft_make_Xx.o ft_printf.o utils.o \
	width_handeler.o

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
	gcc $(SRC) test.c 
	./a.out