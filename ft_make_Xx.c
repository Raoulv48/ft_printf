/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_Xx.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:03 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 18:08:16 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_hexx(t_flag *flags, int data)
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
	if (flags->flag == '-' && flags->precision_bool != 1)
	{
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
		while (i < flags->width - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->sign == '\0' && len > flags->precision && flags->precision > 0)
	{
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
		ft_putchar_fd(towrite, 1);
		if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
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
			// if (flags->width == flags->precision && data < 0)
			// 	ft_putchar_fd('-', 1);
			else
				ft_putchar_fd(towrite, 1);
			flags->width--;
		}
		ft_putchar_fd(towrite, 1);
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putstr_fd(ft_itoa_base(data, 16), 1);
	}
	flags->counter = i + len;
}

void make_xx(t_flag *flags, va_list args)
{
	int	data;
	int	i;

	i = 0;
	data = va_arg(args, int);
	if (data < 0)
	{
	 	data = data * -1;
	 	flags->sign = '-';
	}
	if (flags->precision == 0 && flags->precision_bool == 1)
		flags->counter = 0;
	if (flags->precision == 0 && flags->precision_bool == 1 && flags->width > 0)
		add_spacing_hexx(flags, data);
	else if (flags->width != 0 || flags->precision != 0)
	{
		add_spacing_hexx(flags, data);
		// if (flags->width < flags->precision)
		// 	precision_handler_num(flags, data);
		// else
		// 	width_handler_num(flags, data);
	}
	else
	{
		if (flags->sp_bool == 1)
		{
			if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
			else
				ft_putchar_fd(' ', 1);
		}
		else if (flags->sign != '\0' && flags->sp_bool != 1)
			ft_putchar_fd(flags->sign, 1);
		if (flags->precision_bool != 1)
			ft_putnbr_fd(data, 1);
	}
}