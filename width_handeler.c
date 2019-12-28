/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handeler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:01:58 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/28 19:37:05 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_num(t_flag *flags, int data)
{
	int i;
	int len;
	char towrite;

	towrite = ' ';
	len = getintlen(data);
	if (len == 0)
		len++;
	if (flags->sign == '+')
		len++;
	i = 0;
	// calc length of var, 
	if (flags->flag == '0' || flags->precision_bool == 1)
		towrite = '0';
	if (flags->flag == '-' && flags->precision_bool != 1)
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
		while (flags->width - len > 0)
		{
			// if (flags->width == len && flags->sign == '+')
			// {
			// 	ft_putchar_fd('+', 1);
			// 	flags->sign = '0';
			// }
			if (flags->width - 1 == flags->precision && flags->sign == '-')
			{
				ft_putchar_fd('-', 1);
				flags->sign = '0';
			}
			// else if (flags->width > flags->precision)
			// 	ft_putchar_fd(' ', 1);
			else if (flags->width > len)
				ft_putchar_fd(' ', 1);
			// if (flags->width == flags->precision && data < 0)
			// 	ft_putchar_fd('-', 1);
			else
				write(1, &towrite, 1);
			flags->width--;
		}
		if (flags->width == len && flags->sign == '+')
				ft_putchar_fd('+', 1);
		ft_putnbr_fd(data, 1);
	}
	flags->counter = i + len;
}

void	add_spacing_str(t_flag *flags, char *data)
{
	int i;
	int len;
	char towrite;

	towrite = ' ';
	len = ft_strlen(data);
	i = 0;
	// calc length of var, 
	// if (flags->flag == '0' || flags->precision_bool == 1)
	// 	towrite = '0';
	if (flags->flag == '-' && flags->precision_bool != 1)
	{
		write(1, data, len);
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	// new for fix
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->precision > len)
	{
		write(1, data, len);
		while (i + len < flags->width)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	//test
	// else if (flags->flag == '-' && flags->precision_bool == 1 && flags->precision > len)
	// {
	// 	write(1, data, len);
	// 	while (i + len < flags->width)
	// 	{
	// 		write(1, &towrite, 1);
	// 		i++;
	// 	}
	// }
	// i < flags->width - len // previous test
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->precision < len)
	{
		write(1, data, flags->precision);
		while (i + flags->precision < flags->width)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	else if (flags->flag == '-' && flags->precision_bool == 1 && flags->precision == len)
	{
		write(1, data, flags->precision);
		while (i + flags->precision < flags->width)
		{
			write(1, &towrite, 1);
			i++;
		}
	}
	else if (flags->precision_bool == 1 && flags->precision < len && flags->precision == flags->width)
	{
		write(1, data, flags->precision);
	}
	// else if (flags->flag == '0' || flags->sign == '+')
	// {
	// 	write(1, data, flags->len);
	// 	while (i < flags->width - len)
	// 	{
	// 		write(1, &towrite, 1);
	// 		i++;
	// 	}
	// }
	else if (flags->flag == '0' || flags->sign == '+')
	{
		if (len < flags->precision)
		{
			write(1, data, len);
			while (i < flags->width - len)
			{
				write(1, &towrite, 1);
				i++;
			}
		}
		else if (flags->precision > 0)
		{
			write(1, data, flags->precision);
			while (i + flags->precision < flags->width)
			{
				write(1, &towrite, 1);
				i++;
			}
		}
		else
		{
			while (i < flags->width - len)
			{
				write(1, "0", 1);
				i++;
			}
			write(1, data, len);
		}

	}
	else
	{
		while (i < flags->width - len)
		{
			write(1, &towrite, 1);
			i++;
		}
		write(1, data, len);
	}
	flags->counter = i + len;
	flags->printed = 1;
}

void	add_spacing_str_smaller_precision(t_flag *flags, char *data)
{
	int		i;
	int		len;
	char	towrite;

	i = 0;
	towrite = ' ';
	len = ft_strlen(data);
	while (i < flags->width - len || flags->precision + i < flags->width)
	{
		write(1, &towrite, 1);
		i++;
	}
	if (len < flags->precision)
	{
		write(1, data, len);
		flags->counter = i + len;
	}
	else
	{
		write(1, data, flags->precision);
		flags->counter = i + flags->precision;
	}
	flags->printed = 1;
}

//printf("\n test %c\n", flags->conversion);
void	width_num(t_flag *flags, int data)
{
	if (flags->flag == ' ')
		add_spacing_num(flags, data);
	if (flags->flag == '0')
		add_spacing_num(flags, data);
	if (flags->flag == '-')
		add_spacing_num(flags, data);
	if (flags->flag == 0)
		add_spacing_num(flags, data);
	//if (flags->sign == '+')
}

void	width_string(t_flag *flags, char *data)
{
	if (flags->flag == ' ')
		add_spacing_str(flags, data);
	if (flags->flag == '0' && flags->printed != 1)
		add_spacing_str(flags, data);
	if (flags->flag == '-' && flags->printed != 1)
		add_spacing_str(flags, data);
	if (flags->width > flags->precision && flags->precision_bool == 1 && flags->width_bool == 1 && flags->printed != 1)
		add_spacing_str_smaller_precision(flags, data);
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
