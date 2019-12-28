/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:19 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/28 18:55:02 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_s(t_flag *flags, va_list args)
{
	char	*data;
	int		i;

	i = 0;
	data = va_arg(args, char *);
	if (data == NULL)
		data = "(null)";
	//if (flags->width != 0 || flags->precision != 0)
	if (flags->precision_bool != 0 || flags->width_bool != 0)
	{
		if (flags->width < flags->precision)
			precision_handler_str(flags, data);
		else if (flags->precision_bool != 0 && flags->width_bool == 0)
			precision_handler_str(flags, data);
		else
			width_handler_str(flags, data);
	}
	else
		ft_putstr_fd(data, 1);
}
