/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 15:53:32 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 18:31:02 by rverscho      ########   odam.nl         */
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
	//int			padding;
	int			index;
	char		flag;
	char		sign;
	int			width;
	t_bool		width_bool;
	int			precision;
	t_bool		precision_bool;
	//int			precision_value;
	char		conversion;
	//int			flag_len;
}				t_flag;

t_flag			*empty_flag(void);

int main ();

void			ft_putchar_fd(char c, int fd);
int				ft_printf(const char *str, ...);
//void			ft_printf_handeler(char *str, int i,
//					t_flag *flags, va_list args);

void			ft_main_flag_hand(char *str, t_flag *flags, va_list args);
void			ft_flag_handeler(char *str, t_flag *flags, va_list args);

int				ft_atoi(const char *str);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_intlen(const char *str);
size_t			ft_strlen(const char *str);

void make_c(t_flag *flags, char *str, va_list args);
void make_s(t_flag *flags, char *str, va_list args);
void make_p(t_flag *flags, char *str, va_list args);
void make_d(t_flag *flags, char *str, va_list args);
void make_i(t_flag *flags, char *str, va_list args);
void make_u(t_flag *flags, char *str, va_list args);
void make_x(t_flag *flags, char *str, va_list args);
void make_xx(t_flag *flags, char *str, va_list args);

int				iswhitespace(const char *str, int i);
int				is_specifier(const char *str, int i);
int				is_flag(const char *str, int i);
int				is_num(const char *str, int i);
int				is_precision(const char *str, int i);

void			set_precision(char *str, t_flag *flags, va_list args);
void			set_width(char *str, t_flag *flags, va_list args);
void			set_flag(char *str, t_flag *flags);
void			set_specifier(char *str, t_flag *flags, va_list args);
#endif
