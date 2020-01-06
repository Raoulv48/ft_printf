/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:53:24 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/06 20:46:55 by rverscho      ########   odam.nl         */
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

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

//"% 0+8.5d", 34

	// prf = printf("%3.7ii\n", -2375);
	// ft_prf = ft_printf("%3.7i", -2375);

	// 	prf = printf("%010.5ii\n", -234); //not happy with this fix, ugly
	// ft_prf = ft_printf("%010.5i", -234);




	// prf = printf("%-7.5ss\n", "tubular");
	// ft_prf = ft_printf("%-7.5s", "tubular");

	// prf = printf("%3.7s%7.7ss\n", "hello", "world");
	// ft_prf = ft_printf("%3.7s%7.7s", "hello", "world");

	// prf = printf("%3.7s%3.7ss\n", "hello", "world");
	// ft_prf = ft_printf("%3.7s%3.7s", "hello", "world");

	// prf = printf("%#.5xx\n", 21);
	// ft_prf = ft_printf("%#.5x", 21);

	prf = printf("%.5pi\n", 0);
	ft_prf = ft_printf("%.5p", 0);

	// printf("REAL: %d\n", printf(INPUT));
	// printf("MINE: %d\n", ft_printf(INPUT));
	// prf = printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	// ft_prf = ft_printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	// prf = printf("%9.9pi\n", 1234);
	// ft_prf = ft_printf("%9.9p", 1234);

	// prf = printf("%.3xi\n", 0);
	// ft_prf = ft_printf("%.3x", 0);
	// prf = printf("%#5.0xi\n", 0);
	// ft_prf = ft_printf("%#5.0x", 0);
	
	
	// prf = printf("%-#8.5xi\n", 34);
	// ft_prf = ft_printf("%-#8.5x", 34);

	// prf = printf("%+ 08.5ii\n", 34);
	// ft_prf = ft_printf("%+ 08.5i", 34);



	// prf = printf("%#.5xx\n", 21);
	// ft_prf = ft_printf("%#.5x", 21);

	// prf = printf("% .5ii\n", 2);
	// ft_prf = ft_printf("% .5i", 2);

	// prf = printf("%03.7ii\n", -2375);
	// ft_prf = ft_printf("%03.7i", -2375);
	// prf = printf("%07ii\n", -54);
	// ft_prf = ft_printf("%07i", -54);

//Test  348:  i_width_pos_fits_lj_sp
//Test  349:  i_width_neg_fits_lj_sp
//Test  350:  i_width_zero_fits_lj_sp
//i_prec_width_fit_fit_pos_lj_sp



	// prf = printf("%.6ii\n", -3);
	// ft_prf = ft_printf("%.6i", -3);

	// prf = printf("%05ii\n", 43);
	// ft_prf = ft_printf("%05i", 43);
	

	// prf = printf("%-5.3ii\n", 10);
	// ft_prf = ft_printf("%-5.3i", 10);

	// prf = printf("%-5.3ii\n", 10);
	// ft_prf = ft_printf("%-5.3i", 10);

	// prf = printf("%10.5ii\n", -216);
	// ft_prf = ft_printf("%10.5i", -216);


	// prf = printf("% 10.5ii\n", -216);
	// ft_prf = ft_printf("% 10.5i", -216);

	// prf = printf("% 3.7ii\n", -2375);
	// ft_prf = ft_printf("% 3.7i", -2375);



	// prf = printf("%7.7s%7.7ss\n", "hello", "world");
	// ft_prf = ft_printf("%7.7s%7.7s", "hello", "world");

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