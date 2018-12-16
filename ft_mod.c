/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:34:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/15 14:36:21 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mod(t_data *data)
{
	char	t;
	char	*tmp;

	if (!(tmp = ft_strnew(1)))
		return (NULL);
	t = '%';
	if (!t)
	{
		ft_strdel(&data->prs->tmp);
		t = 0;
	}
	ft_memset((void*)tmp, t, 1);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
