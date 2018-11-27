/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:55:04 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 22:07:00 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list)
{
	int		j;
	int		start;
	int		len;
	char	*tmp;

	j = -1;
	tmp = NULL;
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
		while (j < len && !ft_isconv(data->fmt[j]))
			j++;
		if (ft_isflag(data->fmt[j]))
			ft_lst_push_flag(data, begin_list, start, j);
		else
			ft_lst_push_txt(data, begin_list, start, j);
	}
	return (*begin_list);
}

void	ft_lst_push_txt(t_data *data, t_list **begin_list, int start, int j)
{
	char	*tmp;

	if (!(tmp = ft_strnew(0)))
		exit(0);
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
		if (!(tmp = ft_strnew(0)))
			exit(0);
		if (!(tmp = ft_strsub(data->fmt, start, j - start + 1)))
			exit(0);
		ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 1);
		ft_strdel(&tmp);
	}
}
