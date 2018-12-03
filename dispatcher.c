/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:01:07 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 12:04:44 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*(*g_tab[])(char *str) = {ft_char, ft_string, ft_ptr};

char	*ft_dispatch(char *str)
{
	char	*db;
	int		i;
	int		len;

	len = ft_strlen(str) - 1;
	i = 0;
	db = "cspdiouxXf%";
	while (db[i])
	{
		if (str[len] == db[i])
			break ;
		i++;
	}
	(g_tab[i])(str);
	return (str);
}
