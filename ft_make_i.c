/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:13 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 18:20:36 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_i(t_flag *flags, char *str, va_list args)
{
	ft_putstr_fd((char*)args, 1);
}