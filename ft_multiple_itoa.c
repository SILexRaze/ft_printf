/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:18:19 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/14 20:09:42 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(long long value, int base)
{
	char		*s;
	ull			n;
	int			sign;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (ull)((value < 0) ? -value : value);
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (ull)((value < 0) ? -value : value);
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char		*ft_itoa_bl(long long value, int base)
{
	char			*s;
	ull				n;
	int				sign;
	int				i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (ull)((value < 0) ? -value : value);
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (ull)((value < 0) ? -value : value);
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

size_t		ft_nbr_len(long double value, int *p)
{
	size_t		i;
	long double	n;

	i = (value < 0 ? 2 : 1);
	if (*p == -1)
		*p = 6;
	n = value;
	while ((n /= 10) >= 1)
		i++;
	i += *p;
	return (i);
}

char		*ft_dtoa(long double value, int p)
{
	char		*dst;
	ull			n;
	int			i;
	char		*tmp;

	n = (ull)value;
	if (!(dst = ft_strnew(ft_nbr_len(value, &p) + 3)))
		return (NULL);
	tmp = ft_itoa(n);
	ft_strcat(dst, tmp);
	i = ft_strlen(dst);
	if (p != 0)
	{
		dst[i++] = '.';
		value -= (double)n;
		value = (value < 0 ? -value : value);
		while (p-- > 0)
		{
			n = (ull)(value * 10);
			value *= 10;
			dst[i++] = n + '0';
			value -= (double)n;
		}
		if ((ull)(value * 10) >= 5)
			ft_round(&dst);
	}
	free(tmp);
	return (dst);
}
