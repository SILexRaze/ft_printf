/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/05 15:00:38 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*c;

	c = "salut";

	ft_printf("%10.2s\n", "salut");
	printf("%10.2s\n", "salut");
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
