/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 18:23:55 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;
//	short a = 10;
	c = "salut";

	/*ft_printf("%10.2s\n", "salut");
	printf("%10.2s\n", "salut");
	ft_printf("%10.1x\n", 255);
	printf("%10.1x\n", 255);
	ft_printf("%10.1X\n", 255);
	printf("%10.1X\n", 255);
	printf("p=%10c\n",'v');
	ft_printf("m=%10c\n",'v');
	printf("p%10p\n", c);
	ft_printf("m%10.5p\n", c);
	ft_printf("m=%10.5i\n", 1);
	printf("p=%10.5i\n", 1);
	printf("p=%o\n", 10);
	ft_printf("m=%o\n", 10);
	printf("p=%b\n", 10);
	ft_printf("m=%b\n", 10);
	ft_printf("m=%b\n", 0);
	ft_printf("m=%b\n", 2);
	ft_printf("m=%b\n", 4);
	ft_printf("%50.5f\n", 14527.98723548);
	printf("%50.5f\n", 14527.98723548);
	ft_printf("m=%010d\n", -300);
	printf("p=%010hd\n", a);
	ft_printf("m=% +d\n", 300);
	printf("p=%+d\n", 300);
	printf("p=% d\n", 300);
	ft_printf("m=%hd\n", 38000);
	printf("p=%hd\n", (short)38000);
	ft_printf("m=%ld\n", (long int)123);
	printf("p=%ld\n", (long int)123);
	ft_printf("m=%d\n", (signed char)128);
	printf("p=%d\n", (signed char)128);
	ft_printf("m=%hd\n", (short int)123);
	printf("p=%hd\n", (short int)123);
	ft_printf("%.20f\n", 1.4);
	printf("%.20f\n", 1.4);
	ft_printf("%x\n", 255);
	printf("%x", 255);
	ft_printf("%#x\n", 255);
	printf("%#x", 255);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#o\n", 255);
	printf("%#o", 255);
	ft_printf("%#010X\n", 255);
	printf("%#010X\n", 255);*/
	ft_printf("m=%010d\n", -300);
	printf("m=%010d\n", -300);
	ft_printf("%020f\n", -300.1);
	printf("%020f\n", -300.1);

	(void)ac;
	(void)av;
	return (0);
}
