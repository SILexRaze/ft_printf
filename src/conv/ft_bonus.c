/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:06:36 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 12:32:58 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_bin(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_itoa_base(t, 2);
	ft_accuracy(data);
	ft_f_width(data, ft_strlen(data->prs->tmp));
	return (data->prs->tmp);
}
