/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 17:46:37 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;

	c = "salut";

	ft_printf("'a'\t\t|\t%10c\nsalut\"\t\t|\t%.10s\n", 'a', "salut");
	ft_printf("255\t\t|\t%x\n", 255);
	ft_printf("255\t\t|\t%X\n", 255);
	ft_printf("0.125\t\t|\t%f\n", 0.12399);
	ft_printf("0x*\t\t|\t%p\n", c);
	ft_printf("125\t\t|\t%i\n", 125);
	(void)ac;
	(void)av;
	return (0);
}
