/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_num.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:38:35 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 18:44:13 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_left_num(t_flags *flags, int data)
{
	else if (flags->precision_bool == 1 && flags->precision == 0 && flags -> width > 0 && flags->flag == '-')
	{
		while (flags->width > i)
		{
			if (flags->width > len)
			{	
				if (flags->sign != '\0')
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
				}
				else if (flags->width - flags->precision > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(towrite, 1);
			}
			else
				ft_putchar_fd(towrite, 1);
			i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
	}
}

void	width_handler_num(t_flag *flags, int data)
{
	if (flags->flag == ' ')
		add_spacing_num(flags, data);
	if (flags->flag == '0')
		add_zero_num(flags, data);
	if (flags->flag == '-')
		add_left_num(flags, data);
	if (flags->flag == 0)//empty flag
		add_emptyflag_num(flags, data);
}