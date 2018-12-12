/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:52:38 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 12:23:13 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_f_width(t_data *data, int size)
{
	int		i;
	char	*s;

	s = (data->flags->zero == 1 ? "0" : " ");
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
				data->prs->tmp = ft_strjoind(s, data->prs->tmp);
				data->f_width--;
			}
		}
	}
}

void	ft_accuracy(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = data->prs->tmp;
	while (tmp[i])
	{
		if (i == data->accu)
		{
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
	data->prs->tmp = ft_strdup(tmp);
}

void	ft_accu_int(t_data *data)
{
	char	*zero;
	size_t	len;

	zero = NULL;
	len = ft_strlen(data->prs->tmp);
	if (data->accu > -1 && len < (size_t)data->accu)
	{
		if (!(zero = ft_strnew(data->accu)))
			exit(0);
		ft_memset((void*)zero, 48, data->accu - len);
		if (!(data->prs->tmp = ft_strdjoin(zero, data->prs->tmp)))
			exit(0);
	}
}
