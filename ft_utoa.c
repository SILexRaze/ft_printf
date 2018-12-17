/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:49:44 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 15:27:53 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_utoa(unsigned long long n, int p)
{
	char				*str;
	int					i;
	unsigned long long	nbr;

	nbr = (unsigned long long)n;
	i = 1;
	while ((n /= 10) >= 1)
		i++;
	i = (p < i ? i : i + (p - i));
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
