/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bcwidth_handler.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:07:20 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 21:34:48 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handeler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:01:58 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 20:06:42 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_num(t_flag *flags, int data)
{
	flags->counter = flags->i + flags->len;
}

void	add_spacing_str(t_flag *flags, char *data)
{
	// while (flags->i < flags->width - flags->len)
	// {
	// 	ft_putchar_fd(flags->towrite, 1);
	// 	flags->i++;
	// }
	// write(1, data, flags->len);
	flags->counter = flags->i + flags->len;
	flags->printed = 1;
}


void	width_string(t_flag *flags, char *data)
{
	if (flags->flag == ' ')
		add_spacing_str(flags, data);
	if (flags->flag == '0' && flags->printed != 1)
		add_spacing_str(flags, data);
	if (flags->flag == '-' && flags->printed != 1)
		add_spacing_str(flags, data);

	if (flags->flag != '-' && flags->flag != '0' && flags->flag != ' ' && flags->printed != 1)
		add_spacing_str(flags, data);
}

void	width_handler_num(t_flag *flags, int data)
{
	if (flags->conversion == 'u')
		width_num(flags, data);
	if (flags->conversion == 'd')
		width_num(flags, data);
	if (flags->conversion == 'i')
		width_num(flags, data);
//	if (flags->conversion == 'x')

//	if (flags->conversion == 'X')

//	if (flags->conversion == 'p')
}

void	width_handler_str(t_flag *flags, char *data)
{
	if (flags->conversion == 'c')
		width_string(flags, data);
	if (flags->conversion == 's')
		width_string(flags, data);
}
