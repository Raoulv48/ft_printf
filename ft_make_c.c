/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:06 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/12 17:38:41 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_char(t_flag *flags, int data)
{
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
	{
		flags->i++;
		ft_putchar_fd(' ', 1);
	}
	if (flags->width_bool == 1 && flags->flag != '-')
	{
		while (flags->width > flags->i + 1)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		ft_putchar_fd(data, 1);
	}
	else if (flags->width_bool == 1 && flags->flag == '-')
	{
		ft_putchar_fd(data, 1);
		while (flags->width > flags->i + 1)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	flags->highest = flags->i + 1;
}

void	make_c(t_flag *flags, va_list args)
{
	int		data;

	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	data = va_arg(args, int);
	if (flags->prec_bool != 0 || flags->width_bool != 0)
	{
		add_spacing_char(flags, data);
	}
	else
	{
		ft_putchar_fd(data, 1);
		flags->highest++;
	}
}
