/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:26:23 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/14 16:32:21 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_printf("m=%-10s is a string\n", "this");
	printf("p=%-10s is a string\n", "this");
	//ft_printf("m=%5%a\n");
	//printf("p=%5%a\n");
	return (0);
}
