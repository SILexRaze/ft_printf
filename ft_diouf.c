/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 17:46:36 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char	*ft_float(t_data *data)
{
	double	t;
	int		i;

	t = va_arg(data->ap, double);
	ft_strdel(&(data->prs->tmp));
	if (data->accu == -1)
		data->accu = 6;
	data->prs->tmp = ft_dtoa((t < 0 ? -t : t), data->accu);
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->plus == 1 || t < 0)
		ft_sign(data, t);
	if (data->flags->minus == 1)
	{
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
		i = data->len;
		while (data->prs->tmp[i])
		{
			if (data->prs->tmp[i] != ' ')
				break ;
			i++;
		}
		data->prs->tmp = ft_strjoind(ft_strsub(data->prs->tmp, i, ft_strlen(data->prs->tmp)- i), ft_strsub(data->prs->tmp, 0, data->len));

	}
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	long long	t;
	int			i;

	ft_cast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(ft_abs(t), 10, data->accu);
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->plus == 1 || t < 0)
		ft_sign(data, t);
	if (data->flags->minus == 1)
	{
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
		i = data->len;
		while (data->prs->tmp[i])
		{
			if (data->prs->tmp[i] != ' ')
				break ;
			i++;
		}
		data->prs->tmp = ft_strjoind(ft_strsub(data->prs->tmp, i, ft_strlen(data->prs->tmp)- i), ft_strsub(data->prs->tmp, 0, data->len));

	}
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_utoa(t, data->accu);
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->minus == 1)
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_oct(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(t, 8, data->accu);
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_padding(data);
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		ft_padding(data);
	}
	else
		ft_padding(data);
	if (data->flags->minus == 1)
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}
