/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:26:23 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/14 20:06:12 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_printf("%5d\n", -42);
	printf("%5d\n", -42);
	ft_printf("@moulitest: %.10d\n", -42);
	printf("@moulitest: %.10d\n", -42);
	ft_printf("%+10.5d\n", 4242);
	printf("%+10.5d\n", 4242);
	ft_printf("%10.5d\n", 4242);
	printf("%10.5d\n", 4242);
	ft_printf("%-10.5d\n",-42);
	printf("%-10.5d\n",-42);
	ft_printf("%+05d\n",42);
	printf("%+05d\n",42);
	ft_printf("%3.2d\n",-1);
	printf("%3.2d\n",-1);
	return (0);
}
