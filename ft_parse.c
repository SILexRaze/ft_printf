/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:28:12 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/28 22:53:21 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'c'
			|| c == 's' || c == 'p')
		return (1);
	return (0);
}

int		ft_is_univ_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

void	ft_count_conv(t_data *data, t_list **begin_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->isflag == 1)
			i++;
		tmp = tmp->next;
	}
	data->nb_flag = i;
}

t_flag	*ft_parse_flag(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*f_base;

	j = 0;
	f_base = "#0-+ ";
	if (!(data->flags = (t_flag *)ft_memalloc(sizeof(t_flag))))
		return (0);
	while (f_base[j])
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == f_base[j])
				*((int*)data->flags + j) = 1;
			i++;
		}
		j++;
	}
	return (data->flags);
}

void	ft_main_parsing(t_data *data, t_list **lst)
{
	int	i;

	i = 0;
	*lst = ft_lst_parse_flags(data, lst);
	ft_count_conv(data, lst);
}
