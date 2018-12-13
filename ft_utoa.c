/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:49:44 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/13 14:23:34 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_utoa(unsigned long long n)
{
	char				*str;
	size_t				i;
	unsigned long long	nbr;

	nbr = (unsigned long long)n;
	i = 1;
	while ((n /= 10) >= 1)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}
