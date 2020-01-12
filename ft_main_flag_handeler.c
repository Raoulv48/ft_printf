/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main_flag_handeler.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:04:01 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/12 21:19:30 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flag_handeler(char *str, t_flag *flags, va_list args)
{
	if (is_flag(str, flags->index))
		set_flag(str, flags);
	if (is_num(str, flags->index) || str[flags->index] == '*')
		set_width(str, flags, args);
	if (is_precision(str, flags->index))
		set_precision(str, flags, args);
	if (str[flags->index] != is_specifier(str, flags->index))
		set_specifier(str, flags);
}

void	ft_main_flag_hand(char *str, t_flag *flags, va_list args)
{
	flags->index++;
	ft_flag_handeler(str, flags, args);
	write_de_moeder(flags, args);//for printable not conversion, if not printable stop
	//flags->highest = (flags->width > flags->prec) ? flags->width : flags->prec;
	flags->counter = flags->counter + flags->highest;
	flags = empty_flag(flags);
}

