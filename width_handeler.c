/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handeler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:01:58 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/21 20:12:54 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_num(t_flag *flags, va_list args, char flag, int data)
{
	int i;
	int len;
	char towrite;

	towrite = ' ';
	len = getintlen(data);
	i = 0;
	// calc length of var, 
	if (flag == '0')
		towrite = '0';
	if (flag == '-')
	{
		ft_putnbr_fd(data, 1);
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	else
	{
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
		ft_putnbr_fd(data, 1);
	}
}

void	add_spacing_str(t_flag *flags, va_list args, char flag, char *data)
{
	int i;
	int len;
	char towrite;
//printf("\ntest\n");
	towrite = ' ';
	len = ft_strlen(data);
	i = 0;
	// calc length of var, 
	if (flag == '0')
		towrite = '0';
	if (flag == '-')
	{
		write(1, data, 1);
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	else
	{
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
		write(1, data, 1);
	}
}

void	width_num(t_flag *flags, va_list args, int data)
{
	if (flags->flag == ' ')
		add_spacing_num(flags, args, flags->flag, data);
	if (flags->flag == '0')
		add_spacing_num(flags, args, flags->flag, data);
	if (flags->flag == '-')
		add_spacing_num(flags, args, flags->flag, data);
	//if (flags->sign == '+')
}

void	width_string(t_flag *flags, va_list args, char *data)
{
	if (flags->flag == ' ')
		add_spacing_str(flags, args, flags->flag, data);
	if (flags->flag == '0')
		add_spacing_str(flags, args, flags->flag, data);
	if (flags->flag == '-')
		add_spacing_str(flags, args, flags->flag, data);
	else
		add_spacing_str(flags, args, flags->flag, data);
}

void	width_handler_num(t_flag *flags, va_list args, int data)
{
	if (flags->conversion == 'u')
		width_num(flags, args, data);
	if (flags->conversion == 'd')
		width_num(flags, args, data);
	if (flags->conversion == 'i')
		width_num(flags, args, data);
//	if (flags->conversion == 'x')

//	if (flags->conversion == 'X')

//	if (flags->conversion == 'p')
}

void	width_handler_str(t_flag *flags, va_list args, char *data)
{
	if (flags->conversion == 'c')
		width_string(flags, args, data);
	if (flags->conversion == 's')
		width_string(flags, args, data);
}
