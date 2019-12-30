/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_num_spacing.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:59:46 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 22:01:40 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_num_precision_no_sign(t_flag *flags, int data)
{
	if (flags->flag == '-' && flags->prec_bool == 1 && flags->sign == '\0' && flags->len < flags->prec && flags->sp_bool == 1)
	{
		flags->i--;
		while (flags->i + flags->len < flags->width - (flags->prec - flags->len))
		{
			ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->len == 1)
		{
			flags->i++;
			ft_putchar_fd(flags->towrite, 1);
		}
		ft_putnbr_fd(data, 1);
		flags->i++;
		while (flags->i + flags->len < flags->width)
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
		}
	}
}

void	add_spacing_num_precision_plus_sign(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '-')
	{
		while (flags->i + flags->len < flags->width)
		{
			if (flags->sign != '\0' && flags->i + 1 == flags->width - flags->prec)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
				flags->i++;
			}
			if (flags->width - flags->prec > flags->i)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}

void	add_spacing_num_precision_with_sign_no_fit(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '\0' && flags->len > flags->prec)
	{
		while (flags->i - 1 + flags->len < flags->width)
		{
			if (flags->sign != '\0' && flags->i == flags->width - flags->len)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width - flags->len > flags->i)
				ft_putchar_fd(' ', 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}

void	add_spacing_num_precision_with_sign(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->width_bool == 1 && flags->sp_bool == 1 && flags->sign != '\0')
	{
		while (flags->i - 1 + flags->len < flags->width)
		{
			if (flags->sign != '\0' && flags->i + 1 == flags->width - flags->prec)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
				flags->i++;
			}
			if (flags->width - flags->prec > flags->i)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}

void	add_spacing_num_no_precision(t_flag *flags, int data)
{
	if (flags->prec_bool == 0 && flags->sp_bool == 1 && flags->flag != '0')
	{
		while (flags->i + flags->len < flags->width)
		{
			if (flags->sign != '\0' && flags->i == flags->width - flags->len)
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > flags->i + flags->len)
				ft_putchar_fd(flags->towrite, 1);
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}

void	add_spacing_num_no_precision_zeroflag(t_flag *flags, int data)
{
	if (flags->prec_bool == 0 && flags->sp_bool == 1 && flags->flag == '0')
	{
		while (flags->i + flags->len < flags->width)
		{
			if (flags->sign != '\0')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > flags->i + flags->len)
				ft_putchar_fd(flags->towrite, 1);
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}
