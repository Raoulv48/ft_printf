/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_no_converssion.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 20:45:21 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:34:09 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_no_conversion(t_flag *flags)
{
	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	if (flags->width != 0)
	{
		if (flags->flag == '-')
			ft_putchar_fd(flags->conversion, 1, flags);
		while (flags->i + 1 < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1, flags);
			flags->i++;
		}
		if (flags->flag != '-')
			ft_putchar_fd(flags->conversion, 1, flags);
	}
	else
		ft_putchar_fd(flags->conversion, 1, flags);
	flags->highest = (flags->width >= 1) ? flags->width : 1;
}
