/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:24:29 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 18:47:43 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_list(t_list **begin_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			ft_putstr((char *)tmp->data);
			i += ft_strlen((char *)tmp->data);
			tmp = tmp->next;
		}
	}
	return (i);
}
