/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:13:01 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 19:51:17 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *restrict format, ...)
{
	t_list	*lst;
	t_data	*data;
	int		i;
	va_list	arg;

	i = 0;
	data->fmt = (char *)format;
	lst = NULL;
	va_start(arg, format);
	lst = ft_lst_parse_flags(data, &lst);
	ft_print_list(&lst);
	ft_count_flag(data, &lst);
	printf("%d\n", data->nb_flag);
	va_end(arg);
	return (1);
}
