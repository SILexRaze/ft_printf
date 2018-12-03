/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:20:57 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 17:40:26 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list)
{
	int		len;

	data->prs->j = -1;
	len = ft_strlen(data->fmt);
	while (++(data->prs->j) < len)
	{
		data->prs->s = data->prs->j;
		while (data->prs->j < len && data->fmt[data->prs->j] != '%')
			(data->prs->j)++;
		ft_lst_push_txt(data, begin_list);
		if (!(data->prs->j < len))
			break ;
		data->prs->s = data->prs->j;
		while (data->prs->j < len && ft_is_betw(data->fmt[data->prs->j])
				&& !ft_isconv(data->fmt[data->prs->j]))
			(data->prs->j)++;
		if (ft_isconv(data->fmt[data->prs->j]))
			ft_lst_push_flag(data, begin_list);
		else
			ft_lst_push_txt(data, begin_list);
	}
	return (*begin_list);
}

void	ft_lst_push_txt(t_data *data, t_list **begin_list)
{
	int	sub;

	sub = data->prs->j - data->prs->s;
	if (sub > 0)
	{
		if (!(data->prs->tmp = ft_strsub(data->fmt, data->prs->s, sub)))
			exit(0);
		ft_list_pushback(begin_list, (void *)ft_strdup(data->prs->tmp), 0);
		ft_strdel(&(data->prs->tmp));
	}
}

void	ft_lst_push_flag(t_data *data, t_list **begin_list)
{
	int	sub;

	sub = data->prs->j - data->prs->s;
	if (sub + 1 > 0)
	{
		if (!(data->prs->tmp = ft_strsub(data->fmt, data->prs->s, sub + 1)))
			exit(0);
		if (!ft_strchr(data->prs->tmp, '.'))
			data->accu = -1;
		else
			data->accu = 0;
		data->f_width = -1;
		ft_parse_width_accu(data->prs->tmp, data);
		data->flags = ft_parse_flag(data->prs->tmp, data);
//		printf("\n0=%d / +=%d / -=%d / #=%d /  =%d\n", data->flags->zero, data->flags->plus, data->flags->minus, data->flags->hash, data->flags->space);
//		printf("tmp=\t\t%s\nf_width=\t%d\naccu=\t\t%d\n", data->prs->tmp, data->f_width, data->accu);
		data = ft_dispatch(data);
		ft_list_pushback(begin_list, (void *)ft_strdup(data->prs->tmp), 1);
		ft_strdel(&(data->prs->tmp));
	}
}


