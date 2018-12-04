/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:21:15 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/04 23:55:25 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_f_width(t_data *data, int size)
{
	int		i;
	char	*s;

	if (data->flags->zero == 1)
		s = "0";
	else
		s = " ";
	i = 0;
	if (data->f_width != 0)
	{
		if (data->flags->minus == 1)
		{
			while (data->f_width - size > 0)
			{
				data->prs->tmp = ft_strdjoin(data->prs->tmp, s);
				data->f_width--;
			}
		}
		else
		{
			while (data->f_width - size > 0)
			{
				data->prs->tmp = ft_strjoin(s, data->prs->tmp);
				data->f_width--;
			}
		}
	}
}
