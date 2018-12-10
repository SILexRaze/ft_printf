/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/10 15:26:50 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float(t_data *data)
{
	double	t;

	if (data->accu == -1)
		data->accu = 0;
	t = va_arg(data->ap, double);
	data->prs->tmp = ft_dtoa(t, data->accu);
	ft_f_width(data, ft_strlen(ft_dtoa(t, data->accu)));
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	data->prs->tmp = ft_itoa(t);
	if (t > 0)
	{
		if (data->flags->space == 1)
			data->prs->tmp = ft_strjoin(" ", data->prs->tmp);
		if (data->flags->plus == 1)
		{
			if (data->flags->space == 1)
				data->prs->tmp[0] = (t < 0 ? '-' : '+');
			else 
				data->prs->tmp = ft_strjoin((t < 0 ? "-" : "+"), data->prs->tmp);
		}
	}
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	unsigned long	t;

	t = va_arg(data->ap, unsigned long);
	data->prs->tmp = ft_utoa(t);
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_oct(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	data->prs->tmp = ft_itoa_base(t, 8);
	ft_accu_int(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}

char	*ft_per(t_data *data)
{
	return (data->prs->tmp);
}
