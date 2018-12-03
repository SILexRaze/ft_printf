/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:01:07 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 15:54:34 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*(*g_tab[])(t_data *data) = {ft_char, ft_string, ft_minhex, ft_maxhex,
									ft_float, ft_ptr};

t_data	*ft_dispatch(t_data *data)
{
	char	*db;
	int		i;
	int		len;

	len = ft_strlen(data->prs->tmp) - 1;
	i = 0;
	db = "csxXfpdiou%";
	while (db[i])
	{
		if ((data->prs->tmp)[len] == db[i])
			break ;
		i++;
	}
	data->prs->tmp = (g_tab[i])(data);
	return (data);
}
