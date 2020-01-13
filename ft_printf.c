/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 14:52:32 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:55:30 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_de_moeder(t_flag *flags, va_list args)
{
	if (flags->convr == 'c')
		make_c(flags, args);
	else if (flags->convr == 's')
		make_s(flags, args);
	else if (flags->convr == 'p')
		make_p(flags, args);
	else if (flags->convr == 'i')
		make_i(flags, args);
	else if (flags->convr == 'd')
		make_d(flags, args);
	else if (flags->convr == 'u')
		make_u(flags, args);
	else if (flags->convr == 'x')
		make_x(flags, args);
	else if (flags->convr == 'X')
		make_xx(flags, args);
	else if (flags->convr != '\0')
		make_no_conversion(flags);
	else if (flags->convr == '\0')
		flags->error = -1;
}

void	normal_write(const char *str, t_flag *flags)
{
	ft_putchar_fd(str[flags->index], 1, flags);
	flags->index++;
	flags->counter++;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flag	*flags;

	flags = NULL;
	flags = create_flag(flags);
	flags->index = 0;
	va_start(args, str);
	while (str[flags->index] != '\0' && flags->error != -1)
	{
		if (str[flags->index] != '%')
			normal_write(str, flags);
		if (str[flags->index] == '%' && str[flags->index + 1] == '%')
		{
			flags->index += 2;
			flags->counter++;
			ft_putchar_fd('%', 1, flags);
		}
		if (str[flags->index] == '%' && str[flags->index + 1] != '%')
			ft_main_flag_hand((char*)str, flags, args);
	}
	free(flags);
	va_end(args);
	return (flags->counter);
}
