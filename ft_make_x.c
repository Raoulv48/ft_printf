/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:40:44 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 18:15:47 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_x(t_flag *flags, char *str, va_list args)
{
	ft_putstr_fd((char*)args, 1);
}