/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/14 19:36:44 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(t_data *data)
{
	char	t;
	char	*tmp;

	if (!(tmp = ft_strnew(1)))
		return (NULL);
	t = (char)va_arg(data->ap, int);
	if (!t)
	{
		ft_strdel(&data->prs->tmp);
		t = 0;
	}
	ft_memset((void*)tmp, t, 1);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
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
	//	ft_str_clear(data);
	}
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_minhex(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_bl(t, 16);
	if ((ull)data->accu > (ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accuracy(data);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_f_width(data, ft_strlen(data->prs->tmp) + 2);
		data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
		ft_f_width(data, ft_strlen(data->prs->tmp));
	}
	else
		ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_maxhex(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(t, 16);
	if ((ull)data->accu > (ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accuracy(data);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_f_width(data, ft_strlen(data->prs->tmp) + 2);
		data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
		ft_f_width(data, ft_strlen(data->prs->tmp));
	}
	else
		ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_ptr(t_data *data)
{
	long long	t;

	t = va_arg(data->ap, long long);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_putaddr_to_str(t);
	if ((ull)data->accu > (ull)ft_strlen(data->prs->tmp) || data->accu == 0)
		ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
