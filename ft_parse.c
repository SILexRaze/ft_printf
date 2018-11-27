/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:28:12 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 18:57:42 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'c'
			|| c == 's' || c == 'p')
		return (1);
	return (0);
}

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list)
{
	int		j;
	int		start;
	int		len;
	char	*tmp;

	j = -1;
	tmp = NULL;
	len = ft_strlen(data->fmt);
	while(++j < len)
	{
		start = j;
		while (j < len && data->fmt[j] != '%')
			j++;
		ft_lst_push_txt(data, begin_list, start, j);
		if (!(j < len))
			break ;
		start = j;
		while (j < len && !ft_isflag(data->fmt[j]))
			j++;
		tmp = ft_strsub(data->fmt, start, j - start + 1);
		if (ft_isflag(data->fmt[j]))
			ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 1);
		else
			ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 0);
		ft_strdel(&tmp);
	}
	return (*begin_list);
}

void	ft_lst_push_txt(t_data *data, t_list **begin_list, int start, int j)
{
	char	*tmp;

	if (!(tmp = ft_strnew(0)))
		exit(0);
	if (!(tmp = ft_strsub(data->fmt, start, j - start)))
		exit(0);
	ft_list_pushback(begin_list, (void *)ft_strdup(tmp), 0);
	ft_strdel(&tmp);
}

void	ft_lst_push_flag(t_data *data, t_list **begin_list, int start, int j)
{
	char	*tmp;

	if (!(tmp = ft_strnew(0)))
		exit(0);
	if (!(tmp = ft_strsub(data->fmt, start, j - start + 1)))
		exit(0);
	ft_list_pushback
}
