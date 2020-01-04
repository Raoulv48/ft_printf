/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:50:57 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/04 22:38:46 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_left_str(t_flag *flags, char *data)
{
	if (flags->flag == '-' && flags->prec_bool != 1)
		add_left_no_prec(flags, data);
	else if (flags->flag == '-' && flags->prec_bool == 1 && flags->prec == flags->len)
		add_left_same_prec(flags, data);
	else if (flags->flag == '-' && flags->prec_bool == 1 && flags->fit == 0)
		add_left_len_smaller_prec(flags, data);
	else if (flags->flag == '-' && flags->prec_bool == 1 && flags->fit == 1)
		add_left_len_bigger_prec(flags, data);
}

void	add_zero_str(t_flag *flags, char *data)
{
	if (flags->prec_bool == 1 && flags->prec < flags->len && flags->prec == flags->width && flags->printed == 0)
		add_zero_str_same(flags, data);
	if (flags->width > flags->prec && flags->prec_bool == 1 && flags->width_bool == 1 && flags->printed == 0)
		add_spacing_str_smaller_prec(flags, data);
	if (flags->len < flags->prec && flags->printed == 0)
		add_zero_str_len_smaller(flags, data);
	if (flags->printed == 0)
		add_zero_str_prec_not_zero(flags, data);
}

void	width_handler_str(t_flag *flags, char *data)
{
	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	flags->len = ft_strlen(data);
	//flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	//flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->fit = (flags->len <= flags->prec) ? 0 : 1;
	if (flags->flag == '-' && flags->printed == 0)
		add_left_str(flags, data);
	// else if (flags->flag == '0')
	// 	add_zero_str(flags, data);
	if (flags->flag == 0 && flags->printed == 0)
		add_zero_str(flags, data);
	// else if (flags->flag == 0)
	// 	add_emptyflag_str(flags, data);
}
