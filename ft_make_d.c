/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:01 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 13:10:02 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_d(t_flag *flags, va_list args)
{
	int	data;

	data = va_arg(args, int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_int(flags, data);
}
