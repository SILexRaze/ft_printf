/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 12:06:54 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_data
{
	char			**d_flags;
	char			*fmt;
}					t_data;
int		ft_printf(const char * restrict format, ...);
void	ft_recognize(t_data *ptr);
void	ft_init_flag_base(t_data *ptr);
#endif
