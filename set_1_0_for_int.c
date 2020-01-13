/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_1_0_for_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:54:42 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:41:58 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_1_0_for_int(t_flag *flags, int data)
{
	flags->len = getintlen(data);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->highest = (flags->width >= flags->prec) ? flags->width : flags->prec;
	flags->highest = (flags->highest >= flags->len) ? flags->highest : flags->len;
	flags->bb_var = (flags->highest > flags->len || flags->prec > flags->len) ? 1 : 0;
	flags->write_left = (flags->flag == '-') ? 1 : 0;
	flags->ba_var = (flags->len < flags->highest) ? 1 : 0;
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->bool_sign = (flags->sign == '-' || flags->sign == '+') ? 1 : 0;
	flags->fit = (flags->len <= flags->prec) ? 1 : 0;
	if (flags->sign != '\0' && flags->prec == flags->highest)
		flags->counter++;
	flags->towrite = (flags->len > flags->prec && flags->prec_bool == 1) ? ' ' : flags->towrite;
}

void	set_sign(t_flag *flags)
{
	if (flags->hex_bool == 1)
	{
		flags->hexwbool = 1;
		if (flags->width > flags->prec && flags->flag != '-')
			flags->len += 2;
		else
			flags->len -= 2;
		flags->hex_bool = 0;
		ft_putstr_fd(flags->hex, 1, flags);
	}
	if (flags->bool_sign)
		ft_putchar_fd(flags->sign, 1, flags);
	if (flags->flag == '0' && flags->bool_sign == 1)
		flags->bool_sign = 0;
	if (flags->prec_bool == 1 && flags->bool_sign == 1 && flags->fit == 0)
		flags->bool_sign = 0;
	if (flags->prec_bool && flags->bool_sign == 1 && flags->prec > flags->width && flags->width_bool && flags->flag == '-')
	{
		flags->i--;
		flags->bool_sign = 0;
	}
	if (flags->prec_bool && flags->bool_sign == 1 && flags->prec > flags->width && flags->width_bool)
	{
		flags->i -= 2;
		flags->bool_sign = 0;
	}
	if (flags->prec_bool == 1 && flags->bool_sign == 1)
	{
		flags->i--;
		flags->bool_sign = 0;
	}
}

void	write_int_left(t_flag *flags)
{
	while (flags->i + flags->len < flags->prec)
	{
		set_sign(flags);
		if (flags->i + flags->len < flags->prec)
			ft_putchar_fd(flags->towrite, 1, flags);
		flags->i++;
	}
}

void	write_int_big_fit(t_flag *flags)
{
	if (flags->sign != '\0')
	{
		if (flags->flag != '0')
			flags->i++;
		else if (flags->flag == '0' && flags->width > flags->prec)
			flags->i++;
	}
	while (flags->i < flags->width - flags->prec)
	{
		ft_putchar_fd(' ', 1, flags);
		flags->i++;
	}
	if (flags->sign != '\0' && flags->flag == '0')
		flags->i--;
	set_sign(flags);
	while (flags->i + flags->len < flags->highest)
	{
		ft_putchar_fd(flags->towrite, 1, flags);
		flags->i++;
	}
}

void	write_int_big_width(t_flag *flags)
{
	while (flags->i + flags->len < flags->highest)
	{
		if (flags->flag == '0' && flags->i == flags->width - flags->len && flags->prec_bool)
			set_sign(flags);
		else if (flags->flag == '0' && flags->prec_bool == 0)
			set_sign(flags);
		else if (flags->hex_bool == 1 && flags->i + flags->len == flags->prec)
		{
			flags->hex_bool = 0;
			ft_putstr_fd(flags->hex, 1, flags);
		}
		if (flags->i + flags->len < flags->prec && flags->prec_bool == 1)
			ft_putchar_fd(' ', 1, flags);
		else
			ft_putchar_fd(flags->towrite, 1, flags);
		flags->i++;
	}
}

void	write_int_v(t_flag *flags)
{
	if (flags->sign != 0 && flags->hex_bool == 1)
		flags->i--;
	set_sign(flags);
	while (flags->i + flags->len < flags->highest)
	{
		if (flags->i + flags->len >= flags->prec && flags->prec_bool == 1)
			ft_putchar_fd(' ', 1, flags);
		else
			ft_putchar_fd(flags->towrite, 1, flags);
		flags->i++;
	}
}

void	write_before_int(t_flag *flags)
{
	starting_space(flags);
	if (flags->bb_var == 1 && flags->write_left == 1)
		write_int_left(flags);
	else if (flags->bb_var == 1  && flags->prec_bool == 1 && flags->width_bool == 1 && flags->fit == 1 && flags->hex_bool != 1)// && flags->width > flags->len + flags->prec)
		write_int_big_fit(flags);
	else if (flags->bb_var == 1 && flags->width > flags->prec)
		write_int_big_width(flags);
	else if (flags->bb_var == 1)
		write_int_v(flags);
}
