/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 15:53:32 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/04 16:02:37 by rverscho      ########   odam.nl         */
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
	int			prec;
	t_bool		prec_bool;
	char		conversion;
	t_bool		printed;
	int			counter;
	t_bool		sp_bool;

	//restruct2.0
	int			highest;
	t_bool		bool_sign;
	t_bool		write_left;
	t_bool		bb_var;
	t_bool		bw_var;
	t_bool		ba_var;
	//restruct
	int			i;
	int			len;
	char		towrite;
	t_bool		fit;
	//
}				t_flag;

t_flag			*create_flag(t_flag *empty);
t_flag			*empty_flag(t_flag *empty);

//restruct2.0
void	fill_struct_to_write_int(t_flag *flags, int data);
void	write_before_int(t_flag *flags);
void	write_after_int(t_flag *flags);
void	set_1_0_for_int(t_flag *fags, int data);




// restructure
void			width_handler_num(t_flag *flags, int data);

void			add_spacing_num_precision_no_sign(t_flag *flags, int data);
void			add_spacing_num_precision_plus_sign(t_flag *flags, int data);
void			add_spacing_num_precision_with_sign_no_fit(t_flag *flags, int data);
void			add_spacing_num_precision_with_sign(t_flag *flags, int data);
void			add_spacing_num_no_precision(t_flag *flags, int data);
void			add_spacing_num_no_precision_zeroflag(t_flag *flags, int data);
void	add_spacing_num_precision_with_sign_small_width(t_flag *flags, int data);
void	add_left_num_space(t_flag *flags, int data);

void			add_left_num_no_prec(t_flag *flags, int data);
void			add_left_num_with_len_bigger_prec(t_flag *flags, int data);
void			add_left_num_with_len_smaller_prec_no_sign(t_flag *flags, int data);
void			add_left_num_with_len_smaller_prec_with_sign(t_flag *flags, int data);
void			add_left_num_with_prec(t_flag *flags, int data);

void	add_zero_num(t_flag *flags, int data);

void	add_zero_num_zero_prec(t_flag *flags, int data);
void	add_zero_num_prec(t_flag *flags, int data);

void	width_handler_str(t_flag *flags, char *data);

void	add_left_no_prec(t_flag *flags, char *data);
void	add_left_same_prec(t_flag *flags, char *data);
void	add_left_len_smaller_prec(t_flag *flags, char *data);
void	add_left_len_bigger_prec(t_flag *flags, char *data);

void	add_zero_str_same(t_flag *flags, char *data);
void	add_zero_str_len_smaller(t_flag *flags, char *data);
void	add_spacing_str_smaller_prec(t_flag *flags, char *data);
void	add_zero_str_prec_not_zero(t_flag *flags, char *data);

/*  not needed?void			width_handler_num_spacing(t_flag *flags, int data); */


//
int main ();

void			precision_handler_str(t_flag *flags, char *data);
void			precision_handler_num(t_flag *flags, int data);

void			width_handler_str(t_flag *flags, char *data);
void			width_handler_num(t_flag *flags, int data);

void			ft_putchar_fd(char c, int fd);
int				ft_printf(const char *str, ...);

void			ft_main_flag_hand(char *str, t_flag *flags, va_list args);
void			ft_flag_handeler(char *str, t_flag *flags, va_list args);

void	starting_space(t_flag *flags);
void			ft_putnbr_fd(int nb, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa_base(unsigned long n, int base);
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
