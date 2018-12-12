/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:06:42 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 12:29:33 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lst_clear(t_list **begin_list)
{
	t_list	*tmp;
	char	*t;
	int		i;
	int		s;

	tmp = *begin_list;
	while (tmp)
	{
		s = -1;
		t = NULL;
		if (tmp->isflag == 1)
		{
			i = -1;
			t = (char *)tmp->data;
			while (t[++i])
			{
				if (t[i] == '%' && s == -1)
					s = i;
				if (ft_isconv(t[i]))
					break ;
			}
			tmp->data = ft_strdjoind(ft_strsub(t, 0, (size_t)s), t + i + 1);
		}
		tmp = tmp->next;
	}
}
