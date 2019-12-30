/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:09 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 15:30:14 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_u(t_flag *flags, va_list args)
{
	int	data;
	int	i;

	i = 0;
	data = va_arg(args, int);
	if (data < 0)
	{
	 	data = data * -1;
	 	flags->sign = '-';
	}
	if (flags->precision == 0 && flags->precision_bool == 1)
		flags->counter = 0;
	if (flags->precision == 0 && flags->precision_bool == 1 && flags->width > 0)
		width_handler_num(flags, data);
	else if (flags->width != 0 || flags->precision != 0)
	{
		if (flags->width < flags->precision)
			precision_handler_num(flags, data);
		else
			width_handler_num(flags, data);
	}
	else
	{
		if (flags->sp_bool == 1)
		{
			if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
			else
				ft_putchar_fd(' ', 1);
		}
		else if (flags->sign != '\0' && flags->sp_bool != 1)
			ft_putchar_fd(flags->sign, 1);
		if (flags->precision_bool != 1)
			ft_putnbr_fd(data, 1);
	}
}
