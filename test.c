/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:53:24 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/28 19:50:57 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main ()
{
	static char *s_hidden = "hi low\0don't print me lol\0";
	char *text = "hello";
	int nbr = -1234;
	unsigned int nr = -1234;
	unsigned char a = '\x00';
	int prf;
	int ft_prf;

	prf = printf("%.6i\n", -3);
	ft_prf = ft_printf("%.6i", -3);
	//printf("%d\n", prf);
	printf("%d", ft_prf);


	// prf = printf("%+- 06.04s", s_hidden);
	// ft_prf = ft_printf("%+- 06.04s", s_hidden);
	// printf("%025.10s %025.10d\n", text, nbr);
	// ft_printf("%025.10s %025.10d", text, nbr);

	// printf("%25.10i %25.10s\n", nbr, text);
	// ft_printf("%25.10i %25.10s", nbr, text);
	//write(1, &a, 1);
}