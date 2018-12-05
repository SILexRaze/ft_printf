/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:48:25 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 15:42:49 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pushfront(t_list **begin_list, void *data, int isflag)
{
	t_list	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_elem(data, isflag);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_elem(data, isflag);
}
