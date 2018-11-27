/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/27 19:49:13 by vifonne          ###   ########.fr       */
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
	int				nb_flag;
}					t_data;

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list);
int		ft_printf(const char * restrict format, ...);
int		ft_isflag(char c);
void	ft_count_flag(t_data *data, t_list **begin_list);
void	ft_lst_push_txt(t_data *data, t_list **begin_list, int start, int j);
void	ft_lst_push_flag(t_data *datam, t_list **begin_list, int start, int j);
#endif
