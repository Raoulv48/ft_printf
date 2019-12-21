/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:19 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/21 20:09:44 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_s(t_flag *flags, char *str, va_list args)
{
	// char *tmp;

	// tmp = va_arg(args, char *);
	// ft_putstr_fd(tmp, 1);
	char	*data;
	int		i;

	i = 0;
	data = va_arg(args, char *);
	if (flags->width != 0)
		width_handler_str(flags, args, data);// kan deze shit net
	else
		ft_putstr_fd(data, 1);
}
