/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:01:07 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/05 19:05:08 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*(*g_tab[])(t_data *data) = {ft_char, ft_string, ft_minhex, ft_maxhex,
	ft_float, ft_ptr, ft_int, ft_int, ft_usgd};

void	ft_str_clear(t_data *data)
{
	int		i;
	int		s;
	char	*t;

	s = -1;
	t = (char *)data->prs->tmp;
	i = 0;
	while (t[i])
	{
		if (t[i] == '%' && s == -1)
			s = i;
		if (ft_isconv(t[i]))
			break ;
		i++;
	}
	data->prs->tmp = ft_strdjoin(ft_strsub(t, 0, (size_t)s), t + i + 1);
}

t_data	*ft_dispatch(t_data *data)
{
	char	*db;
	int		i;
	int		len;

	len = ft_strlen(data->prs->tmp) - 1;
	i = 0;
	db = "csxXfpiduo%";
	while (db[i])
	{
		if ((data->prs->tmp)[len] == db[i])
			break ;
		i++;
	}
	data->prs->tmp = (g_tab[i])(data);
	return (data);
}
