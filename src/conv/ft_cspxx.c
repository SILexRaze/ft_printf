/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 11:02:46 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_char(t_data *data)
{
	int		i;

	i = 0;
	while ((data->prs->tmp)[i + 1] && (data->prs->tmp)[i] != 'c')
		i++;
	if ((data->prs->tmp)[i] == 'c')
		(data->prs->tmp)[i + 1] = va_arg(data->ap, int);
	ft_str_clear(data);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_string(t_data *data)
{
	int		i;
	char	*t;

	t = va_arg(data->ap, char *);
	i = 0;
	while ((data->prs->tmp)[i] && (data->prs->tmp)[i] != 's')
		i++;
	if ((data->prs->tmp)[i] == 's')
		data->prs->tmp = ft_strdjoin(data->prs->tmp, t);
	ft_str_clear(data);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_minhex(t_data *data)
{
	int		t;

	t = va_arg(data->ap, int);
	data->prs->tmp = ft_itoa_bl(t, 16);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_maxhex(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	data->prs->tmp = ft_itoa_base(t, 16);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_ptr(t_data *data)
{
	long long	t;

	t = va_arg(data->ap, long long);
	data->prs->tmp = ft_putaddr_to_str(t);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
