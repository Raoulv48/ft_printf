/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 14:52:32 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/12 21:19:46 by rverscho      ########   odam.nl         */
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
	else if (flags->conversion == 's')
		make_s(flags, args);
	else if (flags->conversion == 'p')
		make_p(flags, args);
	else if (flags->conversion == 'i')
		make_i(flags, args);
	else if (flags->conversion == 'd')
		make_d(flags, args);
	else if (flags->conversion == 'u')
		make_u(flags, args);
	else if (flags->conversion == 'x')
		make_x(flags, args);
	else if (flags->conversion == 'X')
		make_xx(flags, args);
	else if (flags->conversion != '\0')
		make_no_conversion(flags);
	// if (flags->conversion == '\0')
	// 	flags->index++;
	//add printable
}

// int		check_to_break(const char *str)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = ft_strlen(str);
// 	//if (str[i] != is_specifier(str[i]))
// 	while (i < j)
// 	{
// 		if (!is_specifier(str, i))
// 			return (1);
// 		//if ()
// 		i++;
// 	}
// 	return (0);
// }


int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flag	*flags;

	flags = NULL;
	flags = create_flag(flags);
	flags->index = 0;
	va_start(args, str);
	while (str[flags->index] != '\0')
	{
		if (str[flags->index] != '%')
		{
			ft_putchar_fd(str[flags->index], 1);
			flags->index++;
			flags->counter++;
		}
		if (str[flags->index] == '%' && str[flags->index + 1] == '%')
		{
			flags->index += 2;
			flags->counter ++;
			ft_putchar_fd('%', 1);
		}
		// if (check_to_break(str) == 0)
		// 	break ;
		// if (str[flags->index] == '%' && str[flags->index + 1] == '\0')
		// 	break ;
		if (str[flags->index] == '%' && str[flags->index + 1] != '%')
			ft_main_flag_hand((char*)str, flags, args);
	}
	free(flags);
	va_end(args);
	return (flags->counter);
}
