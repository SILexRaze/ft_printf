/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:28:12 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 20:26:57 by vifonne          ###   ########.fr       */
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

void	ft_count_flag(t_data *data, t_list **begin_list)
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

/*void	ft_put_nb_flag(t_data *data, t_list **lst)
{
	t_list	*tmp;

}
*/
void	ft_main_parsing(t_data *data, t_list **lst)
{
	int	i;

	i = 0;
	*lst = ft_lst_parse_flags(data, lst);
	ft_count_flag(data, lst);
	ft_put_nb_flag(data, lst);
}
