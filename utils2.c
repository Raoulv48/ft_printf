/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 17:52:22 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/06 19:58:19 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		hex_length(unsigned long a, int base)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / base;
		i++;
	}
	return (i);
}

void		ft_fillstring(unsigned long data, int base, int i, t_flag *flags)
{
	unsigned long	b;
	char			dest[i];

	dest[i] = '\0';
	i--;
	while (data >= (unsigned long)base)
	{
		b = data % base;
		if (b < 10)
			dest[i] = b + 48;
		else if (b >= 10)
			dest[i] = b + 'a' - 10;
		data = data / base;
		i--;
	}
	if (data < 10)
		dest[i] = data + 48;
	else
		dest[i] = (data + 'a' - 10);
	if (flags->conversion == 'x' || flags->conversion == 'p')
		ft_tolower(dest);
	if (flags->conversion == 'X')
		ft_toupper(dest);
}

void	ft_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 102)
			str[i] -= 32;
		i++;
	}
	ft_putstr_fd(str, 1);
}

void	ft_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 70)
			str[i] += 32;
		i++;
	}
	ft_putstr_fd(str, 1);
}
