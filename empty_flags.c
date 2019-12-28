/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 16:31:12 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/28 15:12:02 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	*empty_flag(t_flag *empty)
{
	int counter;
	int index;

	if (empty)
	{
		index = empty->index;
		counter = empty->counter;
		free(empty);
	}
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
	empty->counter = counter;
	empty->index = index;
	empty->printed = 0;
	return (empty);
}