/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_str_left.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:55:11 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/03 22:06:04 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_left_no_prec(t_flag *flags, char *data)
{
	if (flags->flag == '-' && flags->prec_bool != 1)
	{
		write(1, data, flags->len);
		while (flags->i < flags->width - flags->len)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	flags->printed = 1;
}

void	add_left_same_prec(t_flag *flags, char *data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->prec == flags->len)
	{
		write(1, data, flags->prec);
		while (flags->i + flags->prec < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	flags->printed = 1;
}

void	add_left_len_smaller_prec(t_flag *flags, char *data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->fit == 0)
	{
		write(1, data, flags->len);
		while (flags->i + flags->len < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	flags->printed = 1;
}

void	add_left_len_bigger_prec(t_flag *flags, char *data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->fit == 1)
	{
		write(1, data, flags->prec);
		while (flags->i + flags->prec < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	flags->printed = 1;
}
