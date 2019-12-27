/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:40:44 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/27 18:24:22 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_x(t_flag *flags, va_list args)
{
	int	data;
	int	i;

	i = 0;
	data = va_arg(args, int);
	if (flags->width != 0)
		width_handler_num(flags, data);
	else
		ft_putnbr_fd(data, 1);
	flags = empty_flag(flags);
}
