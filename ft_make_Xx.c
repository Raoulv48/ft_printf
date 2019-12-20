/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_Xx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:03 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 18:15:49 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void make_xx(t_flag *flags, char *str, va_list args)
{
	ft_putstr_fd((char*)args, 1);
}