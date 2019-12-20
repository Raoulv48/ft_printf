/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 16:31:12 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/20 16:41:43 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	*empty_flag(void)
{
	t_flag	*empty;

	empty = malloc(sizeof(t_flag));
	if (empty == NULL)
		return (NULL);
	empty->flag = 0;
	empty->width = 0;
	empty->width_bool = 0;
	empty->sign = 0;
	empty->precision_bool = 0;
	empty->precision = 0;
	empty->conversion = 0;
	return (empty);
}