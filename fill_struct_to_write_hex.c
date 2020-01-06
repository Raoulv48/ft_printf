/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct_to_write_hex.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 19:05:08 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/06 20:10:43 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_1_0_for_hex(t_flag *flags, unsigned long data)
{
	flags->len = hex_length(data, 16);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->len = (flags->hex_bool == 1 && hex_length(data, 16) > 0) ? flags->len += 2 : flags->len;
	flags->hex_bool = (data > 0) ? flags->hex_bool : 0 ;
	//
	flags->highest = (flags->width > flags->prec) ? flags->width : flags->prec;
	flags->bb_var = (flags->highest > flags->len || flags->prec > flags->len) ? 1 : 0;
	// if (flags->bb_var == 1)
		flags->write_left = (flags->flag == '-') ? 1 : 0;
	flags->ba_var = (flags->len < flags->highest) ? 1 : 0;
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->bool_sign = (flags->sign == '-' || flags->sign == '+') ? 1 : 0;
	flags->fit = (flags->len > flags->prec) ? 0 : 1;
	flags->towrite = (flags->len > flags->prec && flags->prec_bool == 1) ? ' ' : flags->towrite;
	flags->hex = (flags->conversion == 'x' || flags->conversion == 'p') ? "0x" : "0X";
}

void	before_hex(t_flag *flags, unsigned long data)
{
	set_1_0_for_hex(flags, data);
	// if (flags->flag == '#' && data > 0)
	// 	flags->len = flags->len + 2;
	write_before_int(flags);
}

void	write_hex_zero_prec(t_flag *flags)
{
	if (flags->flag == '-')
	{
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1);
		ft_putchar_fd(' ', 1);
	}
	else if (flags->flag != '-')
	{
		if (flags->width > 0)
			ft_putchar_fd(' ', 1);
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1);
	}
}

void	write_hex(t_flag *flags, unsigned long data)
{
	int i;

	i = hex_length(data, 16);
	if (flags->prec_bool == 1 && flags->prec == 0)
		write_hex_zero_prec(flags);
	else
	{
		if (flags->hex_bool == 1 && data > 0)
			ft_putstr_fd(flags->hex, 1);
		if (data == 0)
			ft_putnbr_fd(data, 1);
		else
			ft_fillstring(data, 16, i, flags);
	}
}

void	after_hex(t_flag *flags)
{
	write_after_int(flags);
}

void	fill_struct_to_write_hex(t_flag *flags, unsigned long data)
{
	before_hex(flags, data);
	write_hex(flags, data);
	after_hex(flags);
}
