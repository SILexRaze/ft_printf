/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/11/28 14:43:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
** FONCTIONS DU MAN 3 STDARG OK POUR LE PROJET
** void     va_start(va_list ap, last);
** type     va_arg(va_list ap, type);
** void     va_copy(va_list dest, va_list src);
** void     va_end(va_list ap);
*/

struct			s_flag
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

typedef struct	s_data
{
	char		**d_flags;
	char		*fmt;
	int			nb_flag;
}				t_data;

t_list			*ft_lst_parse_flags(t_data *data, t_list **begin_list);
int				ft_printf(const char *restrict format, ...);
int				ft_isconv(char c);
int				ft_is_univ_flag(char c);
void			ft_count_conv(t_data *data, t_list **begin_list);
void			ft_lst_push_txt(t_data *data, t_list **begin_list, int start,
					int j);
void			ft_lst_push_flag(t_data *data, t_list **begin_list, int start,
					int j);
void			ft_main_parsing(t_data *data, t_list **lst);

#endif
