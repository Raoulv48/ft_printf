/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_functions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:34:16 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/22 16:28:31 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flag(char *str, t_flag *flags)
{
	while (is_flag(str, flags->index))
	{
		if (str[flags->index] == '+')
			flags->sign = '+';
		if (str[flags->index] == '-')
			flags->flag = '-';
		if (str[flags->index] == ' ')
			flags->flag = ' ';
		if (flags->flag != '-')
		{
			if (str[flags->index] == '0')
				flags->flag = '0';
		}
		if (str[flags->index] == '#')
			flags->flag = '#';
		flags->index++;
	}
}

void	set_width(char *str, t_flag *flags, va_list args)
{
	int start;

	if (str[flags->index] == '*')
	{
		start = va_arg(args, int);
		if (start < 0)
		{
			flags->flag = '-';
			start *= -1;
			flags->width = start;
		}
		else
			flags->width = start;
		flags->index++;
	}
	else
	{
		start = flags->index;
		while (is_num(str, flags->index))
			flags->index++;
		flags->width = ft_atoi(ft_substr(str, start, flags->index));
	}
	if (flags->width != 0)
		flags->width_bool = 1;
}

void	set_precision(char *str, t_flag *flags, va_list args)
{
	int start;

	if (str[flags->index + 1] == '*')
	{
		start = va_arg(args, int);
		if (start < 0)
			flags->precision = 0;
		else
			flags->precision = start;
		flags->index += 2;
	}
	else
	{
		flags->index++;
		start = flags->index;
		while (is_num(str, flags->index))
			flags->index++;
		flags->precision = ft_atoi(ft_substr(str, start, flags->index));
	}
	if (flags->precision > 0)
		flags->precision_bool = 1;
}

void	set_specifier(char *str, t_flag *flags)
{
	if (!is_specifier(str, flags->index))
		flags->conversion = str[flags->index];
	flags->index++;
}
