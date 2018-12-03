/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:21:15 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 17:36:17 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_f_width(t_data *data)
{
	int	i;

	i = 0;
	if (data->f_width != 0)
	{
		if (data->flags->minus == 1)
		{
			while (data->f_width != 0)
			{
				data->prs->tmp = ft_strdjoin(data->prs->tmp, " ");
				data->f_width--;
			}
		}
		else
		{
			while (data->f_width != 0)
			{
				data->prs->tmp = ft_strjoin(" ", data->prs->tmp);
				data->f_width--;
			}
		}
	}
}
