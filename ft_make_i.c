/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:13 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/27 18:24:35 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_i(t_flag *flags, va_list args)
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
	if (flags->width != 0 || flags->precision != 0)
	{
		if (flags->width < flags->precision)
			precision_handler_num(flags, data);
		else
			width_handler_num(flags, data);
	}
	else
		ft_putnbr_fd(data, 1);
	flags = empty_flag(flags);
}
