/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:28:12 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/13 19:03:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_llhh(char *str, t_data **data)
{
	int	count;
	int	i;

	i = ft_strlen(str) - 2;
	count = 0;
	if (str[i] == 'h')
	{
		(*data)->flags->convh++;
		if (str[i - 1] == 'h')
			(*data)->flags->convh++;
	}
	else if (str[i] == 'l')
	{
		(*data)->flags->convl++;
		if (str[i - 1] == 'l')
			(*data)->flags->convl++;
	}
}

t_flag	*ft_parse_flag(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*f_base;

	j = 0;
	f_base = "#0-+ ";
	if (!(data->flags = (t_flag *)ft_memalloc(sizeof(t_flag))))
		return (0);
	while (f_base[j])
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == f_base[j])
			{
				if (j == 1 && ft_is_zero(str, i))
					*((int*)data->flags + j) = 1;
				else if (j != 1)
					*((int*)data->flags + j) = 1;
			}
			i++;
		}
		j++;
	}
	return (data->flags);
}

void	ft_parse_width_accu(char *str, t_data *data)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] > '0' && str[i] <= '9')
		{
			if (str[i - 1] != '.' && data->f_width == -1)
				data->f_width = ft_abs(ft_atoi(str + i));
			else if (data->accu == 0)
				data->accu = ft_abs(ft_atoi(str + i));
		}
		i++;
	}
}
