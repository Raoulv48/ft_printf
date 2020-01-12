/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 12:33:49 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/12 20:35:01 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_specifier(const char *str, int i)
{
	if (str[i] == 'c')
		return (0);
	if (str[i] == 's')
		return (0);
	if (str[i] == 'p')
		return (0);
	if (str[i] == 'i')
		return (0);
	if (str[i] == 'd')
		return (0);
	if (str[i] == 'u')
		return (0);
	if (str[i] == 'x')
		return (0);
	if (str[i] == 'X')
		return (0);
	return (1);
}

int		is_flag(const char *str, int i)
{
	if (str[i] == '+')
		return (1);
	if (str[i] == '-')
		return (1);
	if (str[i] == ' ')
		return (1);
	if (str[i] == '0')
		return (1);
	if (str[i] == '#')
		return (1);
	return (0);
}

int		is_num(const char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int		is_precision(const char *str, int i)
{
	if (str[i] == '.')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		iswhitespace(const char *str, int i)
{
	if (str[i] == ' ')
		return (1);
	if (str[i] == '\n')
		return (1);
	if (str[i] == '\t')
		return (1);
	if (str[i] == '\v')
		return (1);
	if (str[i] == '\f')
		return (1);
	if (str[i] == '\r')
		return (1);
	return (0);
}

void	starting_space(t_flag *flags)
{
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')//maybe remove bool
	{
		if (flags->len > flags->prec && flags->flag != '0')
			flags->i++;
		else if (flags->flag == '0' && flags->width > flags->prec)
			flags->i++;
		else if (flags->flag != '-' && flags->width > flags->prec)
			flags->i++;
		ft_putchar_fd(' ', 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
		nbr = (unsigned int)(nb * -1);
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			c = s[i];
			write(fd, &c, 1);
			i++;
		}
	}
}

int			ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	while (iswhitespace(str, i) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= 922337203685477580)
		{
			if ((sign == -1 && str[i] >= '9') || (sign == 1 && str[i] >= '8'))
				return ((sign == -1) ? 0 : -1);
			result = (result * 10) + (str[i] - '0');
			return ((int)result * sign);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (ft_strlen(s) < len)
		substr = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	else
		substr = malloc(sizeof(char) * (len) + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_intlen(const char *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 9)
		{
			len++;
		}
		i++;
	}
	return (len);
}

int		getintlen(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n >= 1 && n <= 9)
		i++;
	return (i);
}
