/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/04 14:06:19 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_float(t_data *data)
{
	double	t;

	if (data->accu == -1)
		data->accu = 0;
	t = va_arg(data->ap, double);
	return (ft_strdjoin(data->prs->tmp, ft_double_to_array(t, data->accu)));
}

char	*ft_int(t_data *data)
{
	int	t;

	t = va_arg(data->ap, int);
	return (ft_strdjoin(data->prs->tmp, ft_itoa(t)));
}
