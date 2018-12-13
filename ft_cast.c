/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:44:19 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/13 14:12:30 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast(t_data *data, long long *t)
{
	if (data->flags->convh == 1)
		*t = (long long)((short int)va_arg(data->ap, long long));
	else if (data->flags->convh == 2)
		*t = (long long)((signed char)va_arg(data->ap, long long));
	else if (data->flags->convl == 1)
		*t = (long long)((long)va_arg(data->ap, long long));
	else if (data->flags->convl == 2)
		*t = va_arg(data->ap, long long);
	else
		*t = (long long)(va_arg(data->ap, int));
}


void	ft_ucast(t_data *data, unsigned long long *t)
{
	if (data->flags->convh == 1)
		*t = (ull)((unsigned short int)va_arg(data->ap, ull));
	else if (data->flags->convh == 2)
		*t = (ull)((unsigned char)va_arg(data->ap, ull));
	else if (data->flags->convl == 1)
		*t = (ull)((unsigned long)va_arg(data->ap, ull));
	else if (data->flags->convl == 2)
		*t = (ull)((unsigned long long)va_arg(data->ap, ull));
	else
		*t = (ull)va_arg(data->ap, unsigned int);
}

