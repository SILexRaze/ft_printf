/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:28:51 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/16 14:05:16 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_int(t_data *data, long long t)
{
	if (t >= 0 && data->flags->space == 1
			&& (size_t)data->f_width >= ft_strlen(data->prs->tmp))
		data->prs->tmp = ft_strjoind(" ", data->prs->tmp);
	if (t >= 0 && data->flags->plus == 1)
	{
		if (data->flags->space == 1)
			data->prs->tmp[0] = '+';
		else
			data->prs->tmp = ft_strjoind("+", data->prs->tmp);
	}
	ft_f_width(data, ft_strlen(data->prs->tmp));
	if (t < 0 || data->flags->plus == 1)
		ft_place_sign(data->prs->tmp, data);
}

void	ft_place_sign(char *s, t_data *data)
{
	int		i;
	char	sign;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			sign = s[i];
			s[i] = '0';
		}
		i++;
	}
	i = ft_strchr_space(s);
	if (data->accu != -1 && data->flags->minus == 0)
		i = ft_strlen(data->prs->tmp) - (size_t)data->accu - 1;
	if (i < 0 || (data->accu != -1 && data->flags->minus == 1
				&& data->flags->plus == 0))
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		i = 0;
	}
	data->prs->tmp[i] = sign;
}

int		ft_strchr_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-')
			return (i);
		i++;
	}
	return (0);
}
