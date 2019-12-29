/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_handeler.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 17:34:51 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/29 21:39:09 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_precision_num(t_flag *flags, int data)
// {
// 	int i;
// 	int len;
// 	char towrite;

// 	towrite = ' ';
// 	len = getintlen(data);
// 	i = 0;
// 	// calc length of var, 
// 	if (flags->precision_bool == 1)
// 		towrite = '0';
// 	if (flags->flag == '-')
// 	{
// 		ft_putnbr_fd(data, 1);
// 		while (i < flags->precision - len)
// 		{
// 			write(1, &towrite, 1);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i < flags->precision - len)
// 		{
// 			write(1, &towrite, 1);
// 			i++;
// 		}
// 		ft_putnbr_fd(data, 1);
// 	}
// }


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
		ft_putnbr_fd(data, 1);
		while (i < flags->width - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
	}
	else
	{
		while (flags->precision > 0)
		{
			if (flags->sign == '-' || flags->sign == '+')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '0';
				len--;
			}
			if (flags->precision > len)
				ft_putchar_fd(towrite, 1);
			flags->precision--;
		}
		ft_putnbr_fd(data, 1);
	}
	flags->counter = i + len;
}

void	add_precision_str(t_flag *flags, char *data)
{
	int i;
	int len;
	char towrite;

	towrite = ' ';
	len = ft_strlen(data);
	i = 0;
	// calc length of var, 
	// if (flags->precision_bool == 1)
	// 	towrite = '0';
	if (flags->flag == '-' && flags->precision > 0)
	{
		write(1, data, len);
		while (i < flags->width - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
	}
	else if (flags->precision > 0)
	{
		while (i < flags->precision - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		write(1, data, len);
	}
}

void	add_precision_str_no_flag(t_flag *flags, char *data)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(data);
	if (len < flags->precision)
		write(1, data, len);
	else
		write(1, data, flags->precision);
	while (i + len < flags->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

//printf("\n test %c\n", flags->conversion);
void	precision_num(t_flag *flags, int data)
{
	if (flags->flag == ' ')
		add_precision_num(flags, data);
	if (flags->flag == '0')
		add_precision_num(flags, data);
	if (flags->flag == '-')
		add_precision_num(flags, data);
	if (flags->flag == 0)
		add_precision_num(flags, data);
	//if (flags->sign == '+')
}

void	precision_string(t_flag *flags, char *data)
{
	if (flags->flag == ' ')
		add_precision_str(flags, data);
	if (flags->flag == '0')
		add_precision_str(flags, data);
	if (flags->flag == '-')
		add_precision_str(flags, data);
	if (flags->flag == 0)
		add_precision_str_no_flag(flags, data);
}

void	precision_handler_num(t_flag *flags, int data)
{
	if (flags->conversion == 'u')
		precision_num(flags, data);
	if (flags->conversion == 'd')
		precision_num(flags, data);
	if (flags->conversion == 'i')
		precision_num(flags, data);
//	if (flags->conversion == 'x')

//	if (flags->conversion == 'X')

//	if (flags->conversion == 'p')
}

void	precision_handler_str(t_flag *flags, char *data)
{
	if (flags->conversion == 'c')
		precision_string(flags, data);
	if (flags->conversion == 's')
		precision_string(flags, data);
}