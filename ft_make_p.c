/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:16 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/06 20:43:26 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_p(t_flag *flags, va_list args)
{
	unsigned long	data;

	flags->hex_bool = 1;
	data = va_arg(args, unsigned long);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}
