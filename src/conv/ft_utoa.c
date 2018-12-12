/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:49:44 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 12:37:10 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_nlen(unsigned long long nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_utoa(unsigned long long n)
{
	char				*str;
	size_t				i;
	unsigned long long	nbr;
	size_t				tmp;

	nbr = (unsigned long long)n;
	i = ft_nlen(n);
	tmp = i;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (nbr == 0)
		str[0] = 48;
	while (nbr)
	{
		str[i - 1] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	str[tmp] = '\0';
	return (str);
}
