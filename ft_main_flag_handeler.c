/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main_flag_handeler.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:04:01 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 13:07:51 by rverscho      ########   odam.nl         */
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
	if (flags->conversion != '\0')
	{
		write_de_moeder(flags, args);
		flags->counter = flags->counter + flags->highest;
	}
	else
		flags->index = ft_strlen(str);
	flags = empty_flag(flags);
}
