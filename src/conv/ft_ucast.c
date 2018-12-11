/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:59:28 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/11 16:12:13 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_ucast(t_data *data, unsigned long long *t)
{
	if (data->flags->convh == 1)
		return ((unsigned short int)*t);
	else if (data->flags->convh == 2)
		return ((unsigned char)*t);
	else if (data->flags->convl == 1)
		return ((unsigned long int)*t);
	else if (data->flags->convh == 2)
		return ((unsigned long long int)*t);
	return (*t);
}
