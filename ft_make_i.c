/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:13 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 21:40:03 by rverscho      ########   odam.nl         */
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
	if (flags->prec == 0 && flags->prec_bool == 1)
		flags->counter = 0;
	if (flags->prec == 0 && flags->prec_bool == 1 && flags->width > 0)
		width_handler_num(flags, data);
	else if (flags->width != 0 || flags->prec != 0)
	{
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
		if (flags->prec_bool != 1)
			ft_putnbr_fd(data, 1);
	}
}

// {
// 	int	data;
// 	int	i;

// 	i = 0;
// 	data = va_arg(args, int);
// 	if (data < 0)
// 	{
// 	 	data = data * -1;
// 	 	flags->sign = '-';
// 	}
// 	if (flags->prec == 0 && flags->prec_bool == 1)
// 		flags->counter = 0;
// 	if (flags->prec == 0 && flags->prec_bool == 1 && flags->width > 0)
// 		width_handler_num(flags, data);
// 	else if (flags->width != 0 || flags->prec != 0)
// 	{
// 		if (flags->width < flags->prec)
// 			precision_handler_num(flags, data);
// 		else
// 			width_handler_num(flags, data);
// 	}
// 	else
// 	{
// 		if (flags->sp_bool == 1)
// 		{
// 			if (flags->sign != '\0')
// 				ft_putchar_fd(flags->sign, 1);
// 			else
// 				ft_putchar_fd(' ', 1);
// 		}
// 		else if (flags->sign != '\0' && flags->sp_bool != 1)
// 			ft_putchar_fd(flags->sign, 1);
// 		if (flags->prec_bool != 1)
// 			ft_putnbr_fd(data, 1);
// 	}
// }
