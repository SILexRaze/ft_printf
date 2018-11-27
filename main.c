/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:16:34 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 22:08:59 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	tmp;

	if (ac > 1)
	{
		ft_printf("SALUT%.10dCAVA%d%d%d%d%d%d", ft_atoi(av[1]));
		printf("Salut %20s\n", "salut");
	}
	return (0);
}
