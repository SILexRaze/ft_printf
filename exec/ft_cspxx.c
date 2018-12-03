/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 15:53:33 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_char(t_data *data)
{
	int	i;

	i = 0;
	while ((data->prs->tmp)[i] && (data->prs->tmp)[i] != 'c')
		i++;
	if ((data->prs->tmp)[i] == 'c')
		(data->prs->tmp)[i] = va_arg(data->ap, int);
	return (data->prs->tmp);
}

char	*ft_string(t_data *data)
{
	int		i;
	char	*tmp;

	tmp = va_arg(data->ap, char *);
	i = 0;
	while ((data->prs->tmp)[i] && (data->prs->tmp)[i] != 's')
		i++;
	if ((data->prs->tmp)[i] == 's')
	{
		data->prs->tmp[i] = tmp[0];
		data->prs->tmp = ft_strjoin(data->prs->tmp, tmp + 1);
	}
	return (data->prs->tmp);
}

char	*ft_minhex(t_data *data)
{
	return (ft_itoa_base_lower(va_arg(data->ap, int), 16));
}

char	*ft_maxhex(t_data *data)
{
	return (ft_itoa_base(va_arg(data->ap, int), 16));
}

char	*ft_ptr(t_data *data)
{
	return (ft_putaddr_to_str((long long)va_arg(data->ap, long long)));
}
