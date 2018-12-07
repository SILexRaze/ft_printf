/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/07 23:40:11 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;

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
	printf("p=%10.5i\n", 1);*/
//	printf("p=%o\n", 10);
//	ft_printf("m=%o\n", 10);
//	printf("p=%b\n", 10);
	ft_printf("m=%b\n", 10);
	ft_printf("m=%b\n", 0);
	ft_printf("m=%b\n", 2);
	ft_printf("m=%b\n", 4);
//	ft_printf("%50.5f\n", 14527.98723548);
//	printf("%50.5f\n", 14527.98723548);
	(void)ac;
	(void)av;
	return (0);
}
