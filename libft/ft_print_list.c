/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:24:29 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/28 17:37:08 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			ft_putstr((char *)tmp->data);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}
