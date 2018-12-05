/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/05 19:05:25 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_float(t_data *data)
{
	double	t;

	if (data->accu == -1)
		data->accu = 0;
	t = va_arg(data->ap, double);
	data->prs->tmp = ft_strdjoin(data->prs->tmp, ft_dtoa(t, data->accu));
	ft_str_clear(data);
	ft_f_width(data, ft_strlen(ft_dtoa(t, data->accu)));
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	data->prs->tmp = ft_strdjoin(data->prs->tmp, ft_itoa(t));
	ft_str_clear(data);
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	unsigned long	t;

	t = va_arg(data->ap, unsigned long);
	data->prs->tmp = ft_strdjoin(data->prs->tmp, ft_utoa(t));
	ft_str_clear(data);
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
