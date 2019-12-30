/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_str_prec.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 21:19:48 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 21:35:00 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_zero_str_same(t_flag *flags, char *data)
{
	if (flags->prec_bool == 1 && flags->prec < flags->len && flags->prec == flags->width)
	{
		write(1, data, flags->prec);
	}
}

void	add_zero_str_len_smaller(t_flag *flags, char *data)
{
	if (flags->len < flags->prec)
	{
		write(1, data, flags->len);
		while (flags->i < flags->width - flags->len)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
}

void	add_spacing_str_smaller_prec(t_flag *flags, char *data)
{
	int		i;
	int		len;
	char	towrite;

	i = 0;
	towrite = ' ';
	len = ft_strlen(data);
	while (i < flags->width - len || flags->prec + i < flags->width)
	{
		ft_putchar_fd(towrite, 1);
		i++;
	}
	if (len < flags->prec)
	{
		write(1, data, len);
		flags->counter = i + len;
	}
	else
	{
		write(1, data, flags->prec);
		flags->counter = i + flags->prec;
	}
	flags->printed = 1;
}

void	add_zero_str_prec_not_zero(t_flag *flags, char *data)
{
	if (flags->prec > 0)
	{
		write(1, data, flags->prec);
		while (flags->i + flags->prec < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
	else
	{
		while (flags->i < flags->width - flags->len)
		{
			ft_putchar_fd('0', 1);
			flags->i++;
		}
		write(1, data, flags->len);
	}
}
