/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:09 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/22 17:22:14 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_u(t_flag *flags, va_list args)
{
	unsigned int	data;
	int				i;

	i = 0;
	data = va_arg(args, unsigned int);
	if (flags->width != 0)
		width_handler_num(flags, data);
	else
		ft_putnbr_fd(data, 1);
	flags = empty_flag();
}
