/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_Xx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:03 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/22 17:21:32 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_xx(t_flag *flags, va_list args)
{
	int	data;
	int	i;

	i = 0;
	data = va_arg(args, int);
	if (flags->width != 0)
		width_handler_num(flags, data);
	else
		ft_putnbr_fd(data, 1);
	flags = empty_flag();
}
