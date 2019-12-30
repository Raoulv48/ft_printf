/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:06 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 16:49:16 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_char(t_flag *flags, int data)
{
	int i;
	int len;
	char towrite;

	i = 0;
	towrite = ' ';
	len = getintlen(data);
	if (len == 0)
		len++;
	if (flags->sign != '\0')
		len++;
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
	{
		i++;
		ft_putchar_fd(' ', 1);
	}
	if (flags->flag == '0' || flags->precision_bool == 1)
		towrite = '0';
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->sign == '\0' && len > flags->precision && flags->precision > 0)
	{
		ft_putchar_fd(data, 1);
		while (i + len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->sign == '\0' && len < flags->precision && flags->sp_bool == 0)
	{
		if (len == 1)
			i--;
		while (i + len < flags->width - (flags->precision - len))
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		ft_putchar_fd(data, 1);
		if (len == 1)
			i++;
		while (i + len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1  && flags->sign != '\0' && len > flags->precision && flags->precision > 0)
	{
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
		while (i + len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1  && flags->sign != '\0' && len < flags->precision)
	{
		if (flags->sign != '\0')
		{
			ft_putchar_fd(flags->sign, 1);
			i--;
		}
		while (i < flags->precision - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		ft_putchar_fd(data, 1);
		if (flags->sign == '-')
			i++;
		if (data < 10)
			i--;
		while (i - 1 + flags->precision < flags->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->sign == '\0' && len < flags->precision && flags->sp_bool == 1)
	{
		i--;
		while (i + len < flags->width - (flags->precision - len))
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		if (len == 1)
		{
			i++;
			ft_putchar_fd(towrite, 1);
		}
		ft_putchar_fd(data, 1);
		i++;
		while (i + len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (flags->precision_bool == 0 && flags->sp_bool == 1 && flags->flag != '0')
	{
		while (i + len < flags->width)
		{
			if (flags->sign != '\0' && i == flags->width - len)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > i + len)
				ft_putchar_fd(towrite, 1);
			else
				ft_putchar_fd(towrite, 1);
			i++;
		}
		if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 0 && flags->sp_bool == 1 && flags->flag == '0')
	{
		while (i + len < flags->width)
		{
			if (flags->sign != '\0')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > i + len)
				ft_putchar_fd(towrite, 1);
			else
				ft_putchar_fd(towrite, 1);
			i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '\0' && len > flags->precision)
	{
		while (i - 1 + len < flags->width)
		{
			if (flags->sign != '\0' && i == flags->width - len)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width - len > i)
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '\0')
	{
		while (i - 1 + len < flags->width)
		{
			if (flags->sign != '\0' && i + 1 == flags->width - flags->precision)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
				i++;
			}
			if (flags->width - flags->precision > i)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(towrite, 1);
			i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '-')
	{
		while (i + len < flags->width)
		{
			if (flags->sign != '\0' && i + 1 == flags->width - flags->precision)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
				i++;
			}
			if (flags->width - flags->precision > i)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(towrite, 1);
			i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
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
	else if (flags->precision_bool == 1 && flags->precision == 0 && flags -> width > 0)
	{
		while (flags->width > i)
		{
			if (flags->width > len)
			{	
				if (flags->sign != '\0' && i == flags->width - 1)
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
	else if (flags->precision_bool == 1)
	{
		while (flags->width - len > 0)
		{
			if (flags->width > len)
			{	
				if (flags->sign != '\0' && flags->precision > flags->width - 2)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					len--;
				}
				else if (flags->width - flags->precision > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(towrite, 1);
			}
			else
				ft_putchar_fd(towrite, 1);
			flags->width--;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 0 && flags->width_bool == 1 && flags->flag != '-')
	{
		while (flags->width > i + 1)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		ft_putchar_fd(data, 1);
	}
	else if (flags->precision_bool == 0 && flags->width_bool == 1 && flags->flag == '-')
	{
		ft_putchar_fd(data, 1);
		while (flags->width > i + 1)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
	}
	else if (flags->precision_bool == 0)
	{
		while (flags->width - len > 0)
		{
			if (flags->sign != '\0' && towrite == '0')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > len)
				ft_putchar_fd(towrite, 1);
			else
				ft_putchar_fd(towrite, 1);
			flags->width--;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(data, 1);
	}
	flags->counter = i + len;
}

void	make_c(t_flag *flags, va_list args)
{
	int		data;
	int		i;

	i = 0;
	data = va_arg(args, int);
	// if (data == NULL)
	// 	data = "(null)";
	//if (flags->width != 0 || flags->precision != 0)
	if (flags->precision_bool != 0 || flags->width_bool != 0)
	{
		add_spacing_char(flags, data);
		// if (flags->width < flags->precision)
		// 	precision_handler_str(flags, data);
		// else if (flags->precision_bool != 0 && flags->width_bool == 0)
		// 	precision_handler_str(flags, data);
		// else
		// 	width_handler_str(flags, data);
	}
	else
		ft_putchar_fd(data, 1);
}

//test
// {
// 	char	*data;
// 	int		i;

// 	i = 0;
// 	data = va_arg(args, char *);
// 	if (flags->width != 0)
// 		width_handler_str(flags, data);
// 	else
// 		ft_putstr_fd(data, 1);
// 	flags = empty_flag(flags);
// }