/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/03 11:41:35 by vifonne          ###   ########.fr       */
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

typedef struct	s_flag
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
	int			n;
	int			f_width;
	int			accu;
	t_flag		*flags;
}				t_data;
/*
** PARSER
*/
t_list			*ft_lst_parse_flags(t_data *data, t_list **begin_list);
int				ft_isconv(char c);
int				ft_is_univ_flag(char c);
int				ft_is_betw(char c);
t_flag			*ft_parse_flag(char *str, t_data *data);
void			ft_parse_width_accu(char *str, t_data *data);
void			ft_count_conv(t_data *data, t_list **begin_list);
/*
** LST_PUSH
*/
void			ft_lst_push_txt(t_data *data, t_list **begin_list, int start,
					int j);
void			ft_lst_push_flag(t_data *data, t_list **begin_list, int start,
					int j);
void			ft_main_parsing(t_data *data, t_list **lst);
/*
** LE RESTE
*/
int				ft_printf(const char *restrict format, ...);
char			*ft_dispatch(char *str);
/*
** Fonctions d'exec
*/
char			*ft_char(char *str);
char			*ft_string(char *str);
char			*ft_ptr(char *str);
#endif
