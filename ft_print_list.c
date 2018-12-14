/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:24:29 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/14 19:23:34 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_list(t_list **begin_list)
{
	t_list	*tmp;
	int		i;
	char	*str;

	i = 0;
	tmp = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			i += ft_strlen((char *)tmp->data);
			tmp = tmp->next;
		}
		tmp = *begin_list;
		if (!(str = ft_strnew(i)))
			return (0);
		while (tmp)
		{
			ft_strcat(str, (char *)tmp->data);
			tmp = tmp->next;
		}
		ft_putstr(str);
		ft_strdel(&str);
	}
	return (i);
}
