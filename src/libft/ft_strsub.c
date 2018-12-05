/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:34:23 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 16:54:13 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	end;
	size_t	i;

	i = 0;
	if (s)
	{
		end = (size_t)start + len;
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (start < end && s[start])
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
