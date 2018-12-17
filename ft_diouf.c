/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 11:31:24 by vifonne          ###   ########.fr       */
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
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	if (t < 0)
	{
		*(ft_strchr(data->prs->tmp, '-')) = '0';
		data->prs->tmp[0] = '-';
	}
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	long long	t;

	ft_cast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(t, 10);
	data->len = ft_strlen(data->prs->tmp);
	if ((t_ull)data->accu > (t_ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accu_int(data);
	data->len = ft_strlen(data->prs->tmp);
	ft_manage_int(data, t);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_utoa(t);
	if ((t_ull)data->accu > (t_ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accu_int(data);
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_oct(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(t, 8);
	if ((t_ull)data->accu > (t_ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accu_int(data);
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_f_width(data, data->len);
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		ft_f_width(data, data->len);
	}
	else
		ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}
