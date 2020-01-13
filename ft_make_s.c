/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:19 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:27:23 by rverscho      ########   odam.nl         */
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
	if (flags->prec_bool != 0 || flags->width_bool != 0)
		fill_struct_to_write_str(flags, data);
	else
	{
		flags->highest = ft_strlen(data);
		ft_putstr_fd(data, 1, flags);
	}
}
