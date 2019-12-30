/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:53:24 by rverscho       #+#    #+#                */
/*   Updated: 2019/12/30 22:25:04 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main ()
{
	static char *s_hidden = "hi low\0don't print me lol\0";
	char *text = "hello";
	int nbr = -1234;
	unsigned int nr = -1234;
	unsigned char a = '\x00';
	int prf;
	int ft_prf;

	prf = printf("%-3.7ii\n", 3267);
	ft_prf = ft_printf("%-3.7i", 3267);
	//prf = printf("%1c%2c%3c%4c%1c\n",' ','!','"','#','$');
	//ft_prf = ft_printf("%1c%2c%3c%4c%1c",' ','!','"','#','$');
	
//	prf = printf("%3c%4c%1c\n",'"','#','$');
//	ft_prf = ft_printf("%3c%4c%1c",'"','#','$');


	//printf("%d\n", prf);
	printf("%d", ft_prf);


	// prf = printf("%+- 06.04s", s_hidden);
	// ft_prf = ft_printf("%+- 06.04s", s_hidden);
	// printf("%025.10s %025.10d\n", text, nbr);
	// ft_printf("%025.10s %025.10d", text, nbr);

	// printf("%25.10i %25.10s\n", nbr, text);
	// ft_printf("%25.10i %25.10s", nbr, text);
	//write(1, &a, 1);
	//while(1){;}
}