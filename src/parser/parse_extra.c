/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:11:10 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 11:08:59 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'c'
			|| c == 's' || c == 'p' || c == 'f' || c == 'u' || c == 'b')
		return (1);
	return (0);
}

int		ft_is_univ_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' || c == '.')
		return (1);
	return (0);
}

int		ft_is_betw(char c)
{
	if (ft_is_univ_flag(c) || (c > 48 && c < 58) || c == 'l' || c == 'h'
			|| c == '%' || c == 'L')
		return (1);
	return (0);
}

int		ft_is_zero(char *str, int i)
{
	while (str[i] != '%')
	{
		if (str[i] != '0')
			return (0);
		i--;
	}
	return (1);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
