/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 14:52:32 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/21 20:03:42 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//ud same precision handler
//xXp to ITOA_BASE p with 0x
//s 
//c no precision
void	write_de_moeder(t_flag *flags, char *str, va_list args)
{
	if (flags->conversion == 'c')
		make_c(flags, str, args);
	if (flags->conversion == 's')
		make_s(flags, str, args);
	if (flags->conversion == 'p')
		make_p(flags, str, args);
	if (flags->conversion == 'i')
		make_i(flags, str, args);
	if (flags->conversion == 'u')
		make_u(flags, str, args);
	if (flags->conversion == 'x')
		make_x(flags, str, args);
	if (flags->conversion == 'X')
		make_xx(flags, str, args);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flag	*flags;

	flags = empty_flag();
	flags->index = 0;
	va_start(args, str);
	while (str[flags->index] != '\0')
	{
		if (str[flags->index] == '%' && str[flags->index + 1] == '%')
		{
			flags->index += 2;
			ft_putchar_fd('%', 1);
		}
		if (str[flags->index] == '%' && str[flags->index + 1] != '%')
		{
			flags->index++;
			ft_main_flag_hand((char*)str, flags, args);
			write_de_moeder(flags, (char*)str, args);
			flags = empty_flag();
		}
		if (str[flags->index] != '%')
			ft_putchar_fd(str[flags->index], 1);
		flags->index++;
	}
	va_end(args);
	return (flags->index);
}
