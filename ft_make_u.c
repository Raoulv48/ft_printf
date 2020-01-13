/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:09 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 14:48:29 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_u(t_flag *flags, va_list args)
{
	unsigned int	data;

	data = va_arg(args, unsigned int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_int(flags, data);
}
