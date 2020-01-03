/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_handeler.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 17:34:51 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/03 21:02:13 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_end_for_zero_prec(t_flag *flags, int data)
{
	if (flags->prec > 0)
	{
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		ft_putnbr_fd(data, 1);
	}
	else
	{
		(ft_putchar_fd(' ', 1));
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
	}
}

void	add_prec_smaller_width(t_flag *flags, int data)
{
	while (flags->prec > 0)
	{
		if (flags->sign == '-' || flags->sign == '+')
		{
			ft_putchar_fd(flags->sign, 1);
			flags->sign = '0';
			flags->len--;
		}
		if (flags->prec > flags->len)
			ft_putchar_fd(flags->towrite, 1);
		flags->prec--;
	}
	ft_putnbr_fd(data, 1);
	flags->counter = flags->i + flags->len;
	flags->printed = 1;
}

void	add_prec_nofit(t_flag *flags, int data)
{
	if (flags->prec_bool == 1)
	{
		while (flags->width - flags->len > flags->i)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0' && flags->prec == flags->i && flags->prec > 0)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					flags->len--;
				}
				else if (flags->width - flags->prec > flags->i)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->prec > 0)
		{
			if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
			ft_putnbr_fd(data, 1);
		}
		else
		{
			(ft_putchar_fd(' ', 1));
			if (flags->sign != '\0')
				ft_putchar_fd(flags->sign, 1);
		}
		flags->printed = 1;
	}
}

void	add_prec_fit(t_flag *flags, int data)
{
	if (flags->prec_bool == 1)
	{
		while (flags->width - flags->len > flags->i)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0' && flags->width - flags->prec == flags->i + 1)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					flags->len--;
				}
				else if (flags->width - flags->prec > flags->i)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		if (flags->prec > 0)
			ft_putnbr_fd(data, 1);
		flags->printed = 1;
	}
}

void	add_prec_with_width_fit(t_flag *flags, int data)
{
	if (flags->prec_bool == 1)
	{
		while (flags->width - flags->len > flags->i)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0' && flags->prec == flags->i + 1)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					flags->len--;
				}
				else if (flags->width - flags->prec > flags->i)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->i++;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		if (flags->prec > 0)
			ft_putnbr_fd(data, 1);
		flags->printed = 1;
	}
}

void	add_prec_with_width_no_fit(t_flag *flags, int data)
{
	if (flags->prec_bool == 1)
	{
		while (flags->width - flags->len > 0)
		{
			if (flags->width > flags->len)
			{
				if (flags->sign != '\0' && flags->prec > flags->width - 2)
				{
					ft_putchar_fd(flags->sign, 1);
					flags->sign = '\0';
					flags->len--;
				}
				else if (flags->width - flags->prec > 0)
					ft_putchar_fd(' ', 1);
				else
					ft_putchar_fd(flags->towrite, 1);
			}
			else
				ft_putchar_fd(flags->towrite, 1);
			flags->width--;
		}
		if (flags->sign != '\0')
			ft_putchar_fd(flags->sign, 1);
		if (flags->prec > 0)
			ft_putnbr_fd(data, 1);
		flags->printed = 1;
	}
}

void	precision_handler_num(t_flag *flags, int data)
{
	if (flags->width_bool == 0 || flags->width < flags->prec)
		add_prec_smaller_width(flags, data);
	if (flags->sp_bool == 1 && flags->flag == '-')
		add_left_num_space(flags, data);
	if (flags->len < flags->prec && flags->printed == 0)
		add_prec_fit(flags, data);
	if (flags->len > flags->prec && flags->printed == 0)
		add_prec_nofit(flags, data);
	if (flags->width_bool == 1 && flags->fit == 1 && flags->printed == 0)
		add_prec_with_width_no_fit(flags, data);
	if (flags->width_bool == 1 && flags->fit == 0 && flags->printed == 0)
		add_prec_with_width_fit(flags, data);
}




void	add_precision_str(t_flag *flags, char *data)
{
	int 	i;
	int 	len;
	char 	towrite;

	towrite = ' ';
	len = ft_strlen(data);
	i = 0;
	if (flags->flag == '-' && flags->prec > 0)
	{
		write(1, data, len);
		while (i < flags->width - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
	}
	else if (flags->prec > 0)
	{
		while (i < flags->prec - len)
		{
			ft_putchar_fd(towrite, 1);
			i++;
		}
		write(1, data, len);
	}
	flags->printed = 1;
}

void	add_precision_str_no_flag(t_flag *flags, char *data)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(data);
	if (len < flags->prec)
		write(1, data, len);
	else
		write(1, data, flags->prec);
	while (i + len < flags->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	flags->printed = 1;
}

void	precision_string(t_flag *flags, char *data)
{
	if (flags->flag == ' ')
		add_precision_str(flags, data);
	if (flags->flag == '0')
		add_precision_str(flags, data);
	if (flags->flag == '-')
		add_precision_str(flags, data);
	if (flags->flag == 0)
		add_precision_str_no_flag(flags, data);
}

void	precision_handler_str(t_flag *flags, char *data)
{
	if (flags->conversion == 'c')
		precision_string(flags, data);
	if (flags->conversion == 's')
		precision_string(flags, data);
}
