/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_num.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:38:35 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/03 20:05:40 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_handler_num_spacing(t_flag *flags, int data)
{
	// if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')//maybe remove bool
	// {
	// 	flags->i++;
	// 	ft_putchar_fd(' ', 1);
	// }
	if (flags->prec_bool == 0)
		add_spacing_num_no_precision(flags, data);
	if (flags->prec_bool == 1 && flags->sign == '\0' && flags->flag == '-' && flags->printed == 0)
		add_spacing_num_precision_no_sign(flags, data);
	if (flags->prec_bool == 1 && flags->sign == '+' && flags->printed == 0 && flags->width > flags->len)
		add_spacing_num_precision_plus_sign(flags, data);
	if (flags->prec_bool == 1 && flags->sign != '\0' && flags->fit == 0 && flags->width > flags->len && flags->printed == 0)
		add_spacing_num_precision_with_sign(flags, data);
	if (flags->prec_bool == 1 && flags->sign != '\0' && flags->fit == 0 && flags->width < flags->len &&flags->printed == 0)
		add_spacing_num_precision_with_sign_small_width(flags, data);
	if (flags->prec_bool == 1 && flags->sign != '\0' && flags->fit == 1 && flags->printed == 0)
		add_spacing_num_precision_with_sign_no_fit(flags, data);
	if (flags->prec_bool == 1 && flags->flag == '0' && flags->printed == 0)
		add_spacing_num_no_precision_zeroflag(flags, data);
}

void	add_left_num(t_flag *flags, int data)
{
	if (flags->prec_bool == 0 && flags->printed == 0)
		add_left_num_no_prec(flags, data);
	if (flags->prec_bool == 1 && flags->prec == 0 && flags->printed == 0)
		add_left_num_with_prec(flags, data);
	if (flags->fit == 1 && flags->prec > 0 && flags->printed == 0)
		add_left_num_with_len_bigger_prec(flags, data);
	if (flags->fit == 0 && flags->sign == '\0' && flags->width > flags->prec && flags->printed == 0)
		add_left_num_with_len_smaller_prec_no_sign(flags, data);
	if (flags->fit == 0 && flags->sign != '\0' && flags->printed == 0)
		add_left_num_with_len_smaller_prec_with_sign(flags, data);
	if (flags->printed == 0 && flags->sp_bool == 0)
		precision_handler_num(flags, data);
}

void	add_emptyflag_num(t_flag *flags, int data)
{
	if (flags->prec_bool == 0 && flags->printed == 0)
	{
		while (flags->width - flags->len > flags->i)
		{
			if (flags->sign != '\0' && flags->towrite == '0')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > flags->i)
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
		flags->printed = 1;
	}
}

void	add_zero_num(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->prec == 0 && flags->width > 0 && flags->printed == 0)
		add_zero_num_zero_prec(flags, data);
	if (flags->prec_bool == 0 && flags->printed == 0)
		add_emptyflag_num(flags, data);
	if (flags->prec > flags->width && flags->printed == 0)
		precision_handler_num(flags, data);
	// if (flags->printed == 0)
	// 	add_zero_num_prec(flags, data);
}

void	width_handler_num(t_flag *flags, int data)
{
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->len = getintlen(data);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->fit = (flags->len < flags->prec) ? 0 : 1;
	starting_space(flags);
	if (flags->sp_bool == 1 && flags->flag != '-')
		width_handler_num_spacing(flags, data);
	// if (flags->sp_bool == 1 && flags->flag == '-' && flags->prec > flags->width)
	// 	precision_handler_num(flags, data);
	// if (flags->sp_bool == 1 && flags->flag == '-')
	// 	add_left_num_space(flags, data);
	if (flags->flag == '-' && flags->printed == 0)
		add_left_num(flags, data);
	if (flags->flag == '0' && flags->printed == 0)
		add_zero_num(flags, data);
	if (flags->printed == 0)
	{
		if (flags->prec_bool == 0)
			add_emptyflag_num(flags, data);
		if (flags->prec_bool == 1 && flags->printed == 0)
			precision_handler_num(flags, data);
	}
}

/* backup
void	width_handler_num_spacing(t_flag *flags, int data)
{
	// if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')//maybe remove bool
	// {
	// 	flags->i++;
	// 	ft_putchar_fd(' ', 1);
	// }
	while (flags->printed == 0)
	{
		if (flags->prec_bool == 0)
			add_spacing_num_no_precision(flags, data);
		else if (flags->prec_bool == 1 && flags->sign == '\0' && flags->flag == '-')
			add_spacing_num_precision_no_sign(flags, data);
		else if (flags->prec_bool == 1 && flags->sign == '+')
			add_spacing_num_precision_plus_sign(flags, data);
		else if (flags->prec_bool == 1 && flags->sign != '\0')
			add_spacing_num_precision_with_sign(flags, data);
		else if (flags->prec_bool == 1 && flags->sign != '\0' && flags->fit == 1)
			add_spacing_num_precision_with_sign_no_fit(flags, data);
		else if (flags->prec_bool == 1 && flags->flag == '0')
			add_spacing_num_no_precision_zeroflag(flags, data);
		break;
	}
}

void	add_left_num(t_flag *flags, int data)
{
	while (flags->printed == 0)
	{
		if (flags->prec_bool == 0)
			add_left_num_no_prec(flags, data);
		if (flags->prec_bool == 1 && flags->prec == 0)
			add_left_num_with_prec(flags, data);
		if (flags->fit == 1 && flags->prec > 0)
			add_left_num_with_len_bigger_prec(flags, data);
		if (flags->fit == 0 && flags->sign == '\0' && flags->width > flags->prec)
			add_left_num_with_len_smaller_prec_no_sign(flags, data);
		if (flags->fit == 0 && flags->sign != '\0')
			add_left_num_with_len_smaller_prec_with_sign(flags, data);
		else
			precision_handler_num(flags, data);
		break;
	}
}

void	add_emptyflag_num(t_flag *flags, int data)
{
	if (flags->prec_bool == 0)
	{
		while (flags->width - flags->len > 0)
		{
			if (flags->sign != '\0' && flags->towrite == '0')
			{
				ft_putchar_fd(flags->sign, 1);
				flags->sign = '\0';
			}
			if (flags->width > flags->len)
				ft_putchar_fd(flags->towrite, 1);
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->width--;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
}

void	add_zero_num(t_flag *flags, int data)
{
	while (flags->printed == 0)
	{
		if (flags->prec_bool == 1 && flags->prec == 0 && flags->width > 0)
			add_zero_num_zero_prec(flags, data);
		if (flags->prec_bool == 0)
			add_emptyflag_num(flags, data);
		if (flags->prec > flags->width)
			precision_handler_num(flags, data);
		else
			add_zero_num_prec(flags, data);
		break;
	}
}

void	width_handler_num(t_flag *flags, int data)
{
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->len = getintlen(data);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->fit = (flags->len < flags->prec) ? 0 : 1;
	starting_space(flags);
	while (flags->printed == 0)
	{
		if (flags->sp_bool == 1 && flags->flag != '-')
			width_handler_num_spacing(flags, data);
		if (flags->flag == '-')
			add_left_num(flags, data);
		if (flags->flag == '0')
			add_zero_num(flags, data);
		if (flags->flag == 0)
		{
			if (flags->prec_bool == 0 && flags->printed == 0)
				add_emptyflag_num(flags, data);
			if (flags->prec_bool == 1 && flags->printed == 0)
				precision_handler_num(flags, data);
		}
		break;
	}
}
*/