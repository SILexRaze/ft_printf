/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 15:34:02 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float(t_data *data)
{
	double	t;

	if (data->accu == -1)
		data->accu = 0;
	t = va_arg(data->ap, double);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_dtoa(t, data->accu);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	if (t < 0)
	{
		*(ft_strchr(data->prs->tmp, '-')) = '0';
		data->prs->tmp[0] = '-';
	}
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	long long	t;

	t = va_arg(data->ap, int);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(ft_cast(data, &t), 10);
	if (t > 0 && data->flags->space == 1)
		data->prs->tmp = ft_strjoind(" ", data->prs->tmp);
	if (t > 0 && data->flags->plus == 1)
	{
		if (data->flags->space == 1)
			data->prs->tmp[0] = (t < 0 ? '-' : '+');
		else
			data->prs->tmp = ft_strjoind((t < 0 ? "-" : "+"), data->prs->tmp);
	}
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	if (t < 0)
	{
		*(ft_strchr(data->prs->tmp, '-')) = '0';
		data->prs->tmp[0] = '-';
	}
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	unsigned long long	t;

	t = va_arg(data->ap, unsigned long);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_utoa(ft_ucast(data, &t));
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_oct(t_data *data)
{
	unsigned long long	t;

	t = va_arg(data->ap, unsigned long long);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(ft_ucast(data, &t), 8);
	ft_accu_int(data);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_f_width(data, ft_strlen(data->prs->tmp));
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		ft_f_width(data, ft_strlen(data->prs->tmp));
	}
	else
		ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
