/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/04 21:37:59 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;

	c = "salut";

//	ft_printf("%10X\n", 255);
	ft_printf("%20s\n%10X\n%10x\n", c, 255, 255);
//	ft_printf("%010X\n", 255);
//	ft_printf("%-50p\n", c);
//	ft_printf("%050p\n", c);
///	ft_printf("%-50i\n", 125);
//	ft_printf("%050i\n", 125);
//	ft_printf("%-50f\n", 14527.98723548);
//	ft_printf("%050f\n", 14527.98723548);
	(void)ac;
	(void)av;
	return (0);
}
