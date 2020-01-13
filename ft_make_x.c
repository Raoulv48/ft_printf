/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:40:44 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 13:10:27 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_x(t_flag *flags, va_list args)
{
	unsigned long	data;

	data = va_arg(args, unsigned long);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}
