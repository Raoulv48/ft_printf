/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main_flag_handeler.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:04:01 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/21 20:03:17 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flag_handeler(char *str, t_flag *flags, va_list args)
{
	set_flag(str, flags);
	if (is_num(str, flags->index) || str[flags->index] == '*')
		set_width(str, flags, args);
	if (is_precision(str, flags->index))
		set_precision(str, flags, args);
	if (str[flags->index] != is_specifier(str, flags->index))
		set_specifier(str, flags, args);
}

// int		get_temp_str(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (is_specifier(&str[i], i))
// 		i++;
// 	return (i);
// }

void	ft_main_flag_hand(char *str, t_flag *flags, va_list args)
{
	ft_flag_handeler(str, flags, args);
}

