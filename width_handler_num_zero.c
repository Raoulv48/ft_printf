/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_num_zero.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:45:35 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 22:20:24 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_zero_num_zero_prec(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->prec == 0 && flags->width > 0)
	{
		while (flags->width > flags->i)
		{
			if (flags->width > flags->len)
			{	
				if (flags->sign != '\0' && flags->i == flags->width - 1)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
				}
				else if (flags->width - flags->prec > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
	}
	data = 1;
}

void	add_zero_num_prec(t_flag *flags, int data)
{
	if (flags->prec_bool == 1)
	{
		while (flags->width - flags->len > 0)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0' && flags->prec > flags->width - 2)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					flags->len--;
				}
				else if (flags->width - flags->prec > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->width--;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}
