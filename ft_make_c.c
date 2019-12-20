/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:06 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 20:42:23 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_c(t_flag *flags, char *str, va_list args)
{
	char tmp;

	tmp = va_arg(args, int);
	ft_putchar_fd(tmp, 1);
}
