/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:18:19 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 14:06:56 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(long long value, int base)
{
	char		*s;
	long long	n;
	int			sign;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char		*ft_itoa_bl(long long  value, int base)
{
	char		*s;
	long long 	n;
	int			sign;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
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
	if (*p == 0)
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
	long long 	n;
	int			i;

	n = (long long)value;
	if (!(dst = ft_strnew(ft_nbr_len(value, &p) + 2)))
		return (NULL);
	ft_strcat(dst, ft_itoa(n));
	i = ft_strlen(dst);
	dst[i++] = '.';
	value -= (double)n;
	value = (value < 0 ? -value : value);
	while (p-- > 0)
	{
		n = (long long)(value * 10);
		value *= 10;
		dst[i] = n + '0';
		value -= (double)n;
		i++;
	}
	if ((long long)(value * 10) >= 5)
		ft_round(&dst);
	return (dst);
}
