/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:01:07 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 17:38:05 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*(*g_tab[])(t_data *data) = {ft_char, ft_string, ft_minhex, ft_maxhex,
									ft_float, ft_ptr, ft_int};

t_data	*ft_dispatch(t_data *data)
{
	char	*db;
	int		i;
	int		len;

	len = ft_strlen(data->prs->tmp) - 1;
	i = 0;
	db = "csxXfpidou%";
	while (db[i])
	{
		if ((data->prs->tmp)[len] == db[i])
			break ;
		i++;
	}
	ft_f_width(data);
	data->prs->tmp = (g_tab[i])(data);
	return (data);
}
