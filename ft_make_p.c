/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:16 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/22 16:39:58 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_p(t_flag *flags, va_list args)
{
		char	*data;
	int		i;

	i = 0;
	data = va_arg(args, char *);
	if (flags->width != 0)
		width_handler_str(flags, data);
	else
		ft_putstr_fd(data, 1);
	flags = empty_flag();
}