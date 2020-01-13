/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_Xx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:03 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 13:10:35 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_xx(t_flag *flags, va_list args)
{
	long	data;

	data = va_arg(args, long);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}
