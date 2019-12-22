/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 14:52:32 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/22 16:32:05 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/* ud same precision handler
xXp to ITOA_BASE p with 0x
s 
c no precision
printf("\n%c\n", str[flags->index]);
*/
void	write_de_moeder(t_flag *flags, va_list args)
{
	if (flags->conversion == 'c')
		make_c(flags, args);
	if (flags->conversion == 's')
		make_s(flags, args);
	if (flags->conversion == 'p')
		make_p(flags, args);
	if (flags->conversion == 'i')
		make_i(flags, args);
	if (flags->conversion == 'd')
		make_d(flags, args);
	if (flags->conversion == 'u')
		make_u(flags, args);
	if (flags->conversion == 'x')
		make_x(flags, args);
	if (flags->conversion == 'X')
		make_xx(flags, args);
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
		if (str[flags->index] != '%')
		{
			ft_putchar_fd(str[flags->index], 1);
			flags->index++;
		}
		if (str[flags->index] == '%' && str[flags->index + 1] == '%')
		{
			flags->index += 2;
			ft_putchar_fd('%', 1);
		}
		if (str[flags->index] == '%' && str[flags->index + 1] != '%')
			ft_main_flag_hand((char*)str, flags, args);
	}
	va_end(args);
	return (flags->index);
}
