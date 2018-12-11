/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:44:19 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/11 16:48:12 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_cast(t_data *data, long long *t)
{
	if (data->flags->convh == 1)
		return ((short int)*t);
	else if (data->flags->convh == 2)
		return ((signed char)*t);
	else if (data->flags->convl == 1)
		return ((long int)*t);
	else if (data->flags->convh == 2)
		return ((long long int)*t);
	return (*t);
}
