/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/05 19:04:20 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;

	c = "salut";

//	ft_printf("%10.2s\n", "salut");
//	printf("%10.2s\n", "salut");
//	ft_printf("%10.1x\n", 255);
//	printf("%10.1x\n", 255);
//	ft_printf("%10.1X\n", 255);
//	printf("%10.1X\n", 255);
//	printf("pf =%10c\n",'v');
//	ft_printf("our=%10c\n",'v');
//	ft_printf("%10.5p\n", c);
//	printf("%10.5p\n", c);
//	ft_printf("%050p\n", c);
	ft_printf("m=%10.5i\n", 1);
	printf("p=%10.5i\n", 1);
	ft_printf("m=%u\n", 1);
	printf("p=%u\n", 1);
//	ft_printf("%50.5f\n", 14527.98723548);
//	printf("%50.5f\n", 14527.98723548);
	(void)ac;
	(void)av;
	return (0);
}
