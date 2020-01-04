/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct_to_write_int.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 13:06:59 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/04 21:14:16 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	before_var(t_flag *flags, int data)
{
	set_1_0_for_int(flags, data);
	write_before_int(flags);
}

void	write_var_zero_prec(t_flag *flags)
{
	if (flags->flag == '-')
	{
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(' ', 1);
	}
	else if (flags->flag != '-')
	{
		if (flags->width > 0)
			ft_putchar_fd(' ', 1);
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1);
	}
}

void	write_var(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->prec == 0)
		write_var_zero_prec(flags);
	else if (flags->bool_sign == 1)
	{
		ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
	else
		ft_putnbr_fd(data, 1);
}

void	after_var(t_flag *flags)
{
	write_after_int(flags);
}

void	fill_struct_to_write_int(t_flag *flags, int data)
{
	before_var(flags, data);
	write_var(flags, data);
	after_var(flags);
}