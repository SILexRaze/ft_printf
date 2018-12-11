/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/11 12:52:43 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

typedef struct	s_parser
{
	int			s;
	int			j;
	char		*tmp;
}				t_parser;

typedef struct	s_data
{
	char		*fmt;
	int			f_width;
	int			accu;
	t_flag		*flags;
	t_parser	*prs;
	va_list		ap;
}				t_data;
/*
**	PARSER
*/
int				ft_isconv(char c);
int				ft_is_univ_flag(char c);
int				ft_is_betw(char c);
int				ft_is_zero(char *str, int i);
t_flag			*ft_parse_flag(char *str, t_data *data);
t_list			*ft_lst_parse_flags(t_data *data, t_list **begin_list);
void			ft_parse_width_accu(char *str, t_data *data);
void			ft_lst_clear(t_list **begin_list);
void			ft_lst_push_txt(t_data *data, t_list **begin_list);
void			ft_lst_push_mod(t_data *data, t_list **begin_list);
void			ft_lst_push_flag(t_data *data, t_list **begin_list);
void			ft_main_parsing(t_data *data, t_list **lst);
/*
**	LE RESTE
*/
int				ft_printf(const char *restrict format, ...);
int				ft_abs(int nb);
t_data			*ft_dispatch(t_data *data);
void			ft_str_clear(t_data *data);
/*
**	Fonctions d'execution
*/
char			*ft_char(t_data *data);
char			*ft_string(t_data *data);
char			*ft_minhex(t_data *data);
char			*ft_maxhex(t_data *data);
char			*ft_float(t_data *data);
char			*ft_ptr(t_data *data);
char			*ft_int(t_data *data);
char			*ft_usgd(t_data *data);
char			*ft_oct(t_data *data);
char			*ft_per(t_data *data);
char			*ft_bin(t_data *data);
void			ft_f_width(t_data *data, int size);
void			ft_accuracy(t_data *data);
void			ft_accu_int(t_data *data);
/*
**	Fonctions de conversion
*/
char			*ft_itoa_bl(int value, int base);
char			*ft_itoa_base(int value, int base);
char			*ft_dtoa(long double value, int p);
char			*ft_putaddr_to_str(long long value);
char			*ft_utoa(unsigned long n);
void			ft_round(char **str);
#endif
