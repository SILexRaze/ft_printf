/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:13:01 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 10:45:59 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_list	*lst;
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	data->fmt = (char *)format;
	if (data->fmt == NULL)
	{
		ft_strdel(&(data->fmt));
		data->fmt = ft_strdup("(null)\n");
	}
	if (!(data->prs = (t_parser *)malloc(sizeof(t_parser))))
		return (0);
	lst = NULL;
	va_start(data->ap, format);
	ft_main_parsing(data, &lst);
	ft_print_list(&lst);
	va_end(data->ap);
	return (1);
}
