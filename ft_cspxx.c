/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 17:46:39 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char	*ft_char(t_data *data)
{
	char	t;
	char	*tmp;

	if (!(tmp = ft_strnew(1)))
		return (NULL);
	t = (char)va_arg(data->ap, int);
	ft_memset((void*)tmp, t, 1);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_accuracy(data);
	if (t == 0)
	{
		data->len = ft_strlen(data->prs->tmp) + 1;
		data->len = ft_strlen(data->prs->tmp) + 1;
	}
	else
	{
		data->len = ft_strlen(data->prs->tmp);
		ft_f_width(data, data->len);
		data->len = ft_strlen(data->prs->tmp);
	}
	return (data->prs->tmp);
}

char	*ft_string(t_data *data)
{
	char	*t;

	t = va_arg(data->ap, char *);
	if (t == NULL)
	{
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = ft_strdup("(null)");
	}
	else
	{
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = ft_strdup(t);
	}
	ft_accuracy(data);
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_minhex(t_data *data)
{
	t_ull	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_bl(ft_abs(t), 16, data->accu);
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		data->len += 2;
		ft_padding(data);
		data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp) - 2;
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		ft_padding(data);
	}
	else
		ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->minus == 1)
	{
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
	}
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_maxhex(t_data *data)
{
	t_ull	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(ft_abs(t), 16, data->accu);
	data->len = ft_strlen(data->prs->tmp);

	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		data->len += 2;
		ft_padding(data);
		data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp) - 2;
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		ft_padding(data);
	}
	else
		ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->minus == 1)
	{
		data->prs->tmp = ft_strjoin(data->prs->tmp, data->pad);
	}
	else
		data->prs->tmp = ft_strjoin(data->pad, data->prs->tmp);

	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_ptr(t_data *data)
{
	long long	t;

	t = va_arg(data->ap, long long);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_putaddr_to_str(t);
	data->len = ft_strlen(data->prs->tmp);
	if ((t_ull)data->accu > (t_ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accuracy(data);
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}
