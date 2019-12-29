/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 15:53:32 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/29 20:40:51 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef int		t_bool;
enum {	false, true	};

typedef struct	s_flag
{
	int			index;
	char		flag;
	char		sign;
	int			width;
	t_bool		width_bool;
	int			precision;
	t_bool		precision_bool;
	char		conversion;
	t_bool		printed;
	int			counter;
	t_bool		sp_bool;
}				t_flag;

t_flag			*empty_flag(t_flag *empty);

int main ();

void			precision_handler_str(t_flag *flags, char *data);
void			precision_handler_num(t_flag *flags, int data);

void			width_handler_str(t_flag *flags, char *data);
void			width_handler_num(t_flag *flags, int data);

void			ft_putchar_fd(char c, int fd);
int				ft_printf(const char *str, ...);

void			ft_main_flag_hand(char *str, t_flag *flags, va_list args);
void			ft_flag_handeler(char *str, t_flag *flags, va_list args);

void			ft_putnbr_fd(int nb, int fd);
int				ft_atoi(const char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_intlen(const char *str);
size_t			ft_strlen(const char *str);

void			make_c(t_flag *flags, va_list args);
void			make_s(t_flag *flags, va_list args);
void			make_p(t_flag *flags, va_list args);
void			make_d(t_flag *flags, va_list args);
void			make_i(t_flag *flags, va_list args);
void			make_u(t_flag *flags, va_list args);
void			make_x(t_flag *flags, va_list args);
void			make_xx(t_flag *flags, va_list args);

void			write_de_moeder(t_flag *flags, va_list args);

int				getintlen(int n);

int				iswhitespace(const char *str, int i);
int				is_specifier(const char *str, int i);
int				is_flag(const char *str, int i);
int				is_num(const char *str, int i);
int				is_precision(const char *str, int i);

void			set_precision(char *str, t_flag *flags, va_list args);
void			set_width(char *str, t_flag *flags, va_list args);
void			set_flag(char *str, t_flag *flags);
void			set_specifier(char *str, t_flag *flags);
#endif
