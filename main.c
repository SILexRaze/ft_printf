/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:47:20 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 12:15:00 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%10d\n", 12);
	return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	t_data	*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (0);
	va_start(ap, format);
	ptr->fmt = (char *)format;
	ft_init_flag_base(ptr);
	ft_recognize(ptr);
	va_end(ap);
	return (0);
}

void	ft_recognize(t_data *ptr)
{
	int		i;
	int		j;
	int		n;

	n = -1;
	i = 0;
	j = 0;
	while (ptr->fmt[i] && ptr->d_flags[0][j])
	{
		while (ptr->fmt[i] && ptr->d_flags[0][j] && ptr->d_flags[0][j] == '*' && ptr->fmt[i] >= '0' && ptr->fmt[i] <= '9')
		{
			if (n == -1)
				n = i;
			i++;
		}
		if (n != -1)
			j++;
		if (ptr->d_flags[0][j] == ptr->fmt[i])
		{
			ft_putchar('|');
			ft_putchar(ptr->fmt[i]);
			ft_putchar('|');
			ft_putchar('\n');
			j++;
			i++;
		}
		else
		{
			i++;
		}
	}
	printf("|%d|\n", ft_atoi(ptr->fmt + n));
}
