/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:28:12 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/04 01:04:26 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
			{
				if (j == 1 && ft_is_zero(str, i))
					*((int*)data->flags + j) = 1;
				else if (j != 1)
					*((int*)data->flags + j) = 1;
			}
			i++;
		}
		j++;
	}
	return (data->flags);
}

void	ft_parse_width_accu(char *str, t_data *data)
{
	int	i;

	i = 1;
	if (!(ft_strchr(str, '.')))
		data->accu = -1;
	else
		data->accu = 0;
	data->f_width = 0;
	while (str[i - 1])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (data->accu == -1)
				data->f_width = ft_abs(ft_atoi(str + i - 1));
			else if (str[i - 1] == '.')
				data->accu = ft_abs(ft_atoi(str + i));
		}
		i++;
	}
}

void	ft_main_parsing(t_data *data, t_list **lst)
{
	int	i;

	i = 0;
	*lst = ft_lst_parse_flags(data, lst);
}
