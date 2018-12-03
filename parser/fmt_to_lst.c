/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:20:57 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 12:04:43 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list)
{
	int		j;
	int		start;
	int		len;

	j = -1;
	len = ft_strlen(data->fmt);
	while (++j < len)
	{
		start = j;
		while (j < len && data->fmt[j] != '%')
			j++;
		ft_lst_push_txt(data, begin_list, start, j);
		if (!(j < len))
			break ;
		start = j;
		while (j < len && ft_is_betw(data->fmt[j]) && !ft_isconv(data->fmt[j]))
			j++;
		if (ft_isconv(data->fmt[j]))
			ft_lst_push_flag(data, begin_list, start, j);
		else
			ft_lst_push_txt(data, begin_list, start, j);
	}
	return (*begin_list);
}

void	ft_lst_push_txt(t_data *data, t_list **begin_list, int start, int j)
{
	char	*tmp;

	tmp = NULL;
	if (j - start > 0)
	{
		if (!(tmp = ft_strsub(data->fmt, start, j - start)))
			exit(0);
		ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 0);
		ft_strdel(&tmp);
	}
}

void	ft_lst_push_flag(t_data *data, t_list **begin_list, int start, int j)
{
	char	*tmp;

	if (j - start + 1 > 0)
	{
		if (!(tmp = ft_strsub(data->fmt, start, j - start + 1)))
			exit(0);
		if (!ft_strchr(tmp, '.'))
			data->accu = -1;
		else
			data->accu = 0;
		data->f_width = -1;
		ft_parse_width_accu(tmp, data);
		data->flags = ft_parse_flag(tmp, data);
		//printf("\n0=%d / +=%d / -=%d / #=%d /  =%d\n", data->flags->zero, data->flags->plus, data->flags->minus, data->flags->hash, data->flags->space);
		//printf("tmp=\t\t%s\nf_width=\t%d\naccu=\t\t%d\n", tmp, data->f_width, data->accu);
		ft_dispatch(tmp);
		ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 1);
		ft_strdel(&tmp);
	}
}
