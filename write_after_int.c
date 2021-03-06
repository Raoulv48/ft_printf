/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_after_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:39:42 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:31:26 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	finish_int_left(t_flag *flags)
{
	flags->i = (flags->len > flags->prec) ? flags->len : flags->prec;
	if (flags->sign != '\0' && flags->width > flags->prec && flags->prec_bool && flags->fit == 1)
		flags->i++;
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
		flags->i++;
	if (flags->hexwbool == 1)
		flags->i += 2;
	while (flags->i < flags->highest)
	{
		ft_putchar_fd(' ', 1, flags);
		flags->i++;
	}
}

void	write_after_int(t_flag *flags)
{
	if (flags->ba_var == 1 && flags->write_left == 1)
		finish_int_left(flags);
}
