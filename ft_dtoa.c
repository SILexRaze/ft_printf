/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:38:52 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 23:05:19 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_nbr_len(long double value, int p)
{
	size_t		i;
	long double	n;

	i = (value < 0 ? 2 : 1);
	n = value;
	while ((n /= 10) >= 1)
		i++;
	i += p;
	return (i);
}

char		*ft_dtoa(long double value, int p)
{
	char		*dst;
	t_ull		n;
	int			i;

	n = (t_ull)((value < 0) ? -value : value);
	if (!(dst = ft_alloc(value, p)))
		return (NULL);
	i = ft_strlen(dst);
	if (p != 0)
	{
		dst[i++] = '.';
		value -= (double)n;
		value = (value < 0 ? -value : value);
		while (p-- > 0)
		{
			n = (t_ull)(value * 10);
			value *= 10;
			dst[i++] = n + '0';
			value -= (double)n;
		}
		if ((t_ull)(value * 10) >= 5)
			ft_round(&dst);
	}
	return (dst);
}

char		*ft_alloc(long double value, int p)
{
	t_ull	n;
	char	*tmp;
	char	*dst;

	n = (t_ull)((value < 0) ? -value : value);
	if (!(dst = ft_strnew(ft_nbr_len(value, p) + 3)))
		return (NULL);
	if (!(tmp = ft_itoa(n)))
		return (NULL);
	ft_strcat(dst, tmp);
	ft_strdel(&tmp);
	return (dst);
}
