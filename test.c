/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:53:24 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/03 22:08:07 by rverscho      ########   odam.nl         */
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

//Test  348:  i_width_pos_fits_lj_sp
//Test  349:  i_width_neg_fits_lj_sp
//Test  350:  i_width_zero_fits_lj_sp
//i_prec_width_fit_fit_pos_lj_sp


	// prf = printf("%10.5ii\n", -216);
	// ft_prf = ft_printf("%10.5i", -216);


	// prf = printf("% 10.5ii\n", -216);
	// ft_prf = ft_printf("% 10.5i", -216);

	// prf = printf("% 3.7ii\n", -2375);
	// ft_prf = ft_printf("% 3.7i", -2375);



	prf = printf("%7.7s%7.7ss\n", "hello", "world");
	ft_prf = ft_printf("%7.7s%7.7s", "hello", "world");

	// prf = printf("%+5.ii\n", 0);
	// ft_prf = ft_printf("%+5.i", 0);


//important!!!!!!
	// prf = printf("% 08.5ii\n", 34);
	// ft_prf = ft_printf("% 08.5i", 34);
	// prf = printf("% -8.5ii\n", 34);
	// ft_prf = ft_printf("% -8.5i", 34);



	// prf = printf("%-3.7ii\n", 3267);
	// ft_prf = ft_printf("%-3.7i", 3267);


	// prf = printf("% -3.7ii\n", 3267);
	// ft_prf = ft_printf("% -3.7i", 3267);


	//prf = printf("%1c%2c%3c%4c%1c\n",' ','!','"','#','$');
	//ft_prf = ft_printf("%1c%2c%3c%4c%1c",' ','!','"','#','$');
	
//	prf = printf("%3c%4c%1c\n",'"','#','$');
//	ft_prf = ft_printf("%3c%4c%1c",'"','#','$');


	//printf("%d\n", prf);
	printf("i\n");
	printf("%i\n", ft_prf);


	// prf = printf("%+- 06.04s", s_hidden);
	// ft_prf = ft_printf("%+- 06.04s", s_hidden);
	// printf("%025.10s %025.10d\n", text, nbr);
	// ft_printf("%025.10s %025.10d", text, nbr);

	// printf("%25.10i %25.10s\n", nbr, text);
	// ft_printf("%25.10i %25.10s", nbr, text);
	//write(1, &a, 1);
	//while(1){;}
}