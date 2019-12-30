/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_num_left.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:11:28 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 22:01:28 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_left_num_no_prec(t_flag *flags, int data)
{
	if (flags->flag == '-' && flags->prec_bool == 0)
	{
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
		while (flags->i < flags->width - flags->len)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
	}
}

void	add_left_num_with_len_bigger_prec(t_flag *flags, int data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->sign == '\0' && flags->fit == 1 && flags->prec > 0)
	{
		ft_putnbr_fd(data, 1);
		while (flags->i + flags->len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
		}
	}
	else if (flags->flag == '-' && flags->prec_bool == 1  && flags->sign != '\0' && flags->fit == 1 && flags->prec > 0)
	{
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
		while (flags->i + flags->len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
		}
	}
}

void	add_left_num_with_len_smaller_prec_no_sign(t_flag *flags, int data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->sign == '\0' && flags->len < flags->prec && flags->sp_bool == 0)
	{
		if (flags->len == 1)
			flags->i--;
		while (flags->i + flags->len < flags->width - (flags->prec - flags->len))
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		ft_putnbr_fd(data, 1);
		if (flags->len == 1)
			flags->i++;
		while (flags->i + flags->len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
		}
	}
}

void	add_left_num_with_len_smaller_prec_with_sign(t_flag *flags, int data)
{
	if (flags->flag == '-' && flags->prec_bool == 1  && flags->sign != '\0' && flags->len < flags->prec)
	{
		if (flags->sign != '\0')
		{
			ft_putchar_fd(flags->sign, 1);
			flags->i--;
		}
		while (flags->i < flags->prec - flags->len)
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		ft_putnbr_fd(data, 1);
		if (flags->sign == '-')
			flags->i++;
		if (data < 10)
			flags->i--;
		while (flags->i - 1 + flags->prec < flags->width)
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
		}
	}
}

void	add_left_num_with_prec(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->prec == 0 && flags->width > 0 && flags->flag == '-')
	{
		while (flags->width > flags->i)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0')
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
				}
				else if (flags->width - flags->prec > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
	}
	data = 1;//bs
}

