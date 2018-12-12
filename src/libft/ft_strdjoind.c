/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:56:10 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/12 11:57:41 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoind(char *s1, char *s2)
{
	char	*str;

	if (s2)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		ft_strdel(&s2);
		ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}