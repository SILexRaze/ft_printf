/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:28:51 by vifonne           #+#    #+#             */
/*   Updated: 2018/12/17 14:15:46 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_int(t_data *data, long long t)
{
	if (t >= 0 && data->flags->space == 1
			&& (size_t)data->f_width >= ft_strlen(data->prs->tmp) 
			&& data->flags->zero != 1)
		data->prs->tmp = ft_strjoind(" ", data->prs->tmp);
	if (t >= 0 && data->flags->plus == 1)
	{
		if (data->flags->space == 1)
			data->prs->tmp[0] = '+';
		else
			data->prs->tmp = ft_strjoind("+", data->prs->tmp);
	}
	ft_f_width(data, ft_strlen(data->prs->tmp));
	if (t >= 0 && data->flags->space == 1
			&& (size_t)data->f_width >= ft_strlen(data->prs->tmp) 
			&& data->flags->zero == 1)
		data->prs->tmp[0] = ' ';
//	ft_f_width_int(data, t);
	if (t < 0 || data->flags->plus == 1)
		ft_place_sign(data->prs->tmp, data);
}

void	ft_place_sign(char *s, t_data *data)
{
	int		i;
	char	sign;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			sign = s[i];
			s[i] = '0';
		}
		i++;
	}
	i = ft_strchr_space(s);
	if (data->accu != -1 && data->flags->minus == 0)
		i = ft_strlen(data->prs->tmp) - (size_t)data->accu - 1;
	if (i < 0 || (data->accu != -1 && data->flags->minus == 1
				&& data->flags->plus == 0))
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		i = 0;
	}
	if (data->flags->zero == 1 && data->f_width > 0)
		data->prs->tmp[i] = sign;
	else if (data->f_width > 0 || data->accu > 0)
	{
		i = 0;
		while (data->prs->tmp[i])
		{
			if (data->prs->tmp[i] > '0' && data->prs->tmp[i] <= '9')
				break ;
			i++;
		}
		data->prs->tmp[i - 1] = sign;
	}
	else if (data->f_width < 1)
	{
		data->prs->tmp = ft_strjoind(&sign, data->prs->tmp);
	}
}

int		ft_strchr_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-')
			return (i);
		i++;
	}
	return (0);
}

/*void	ft_f_width_int(t_data *data)
  {
  --> Si pas de flag 0
  -->S'il y a le flag + ou que nb < 0
  --> On place le signe + ou - (join)
  --> On applique la precision
  --> On applique le flag ' '
  -->S'il y a le flag - 
  --> On applique la largeur de champ avec des ' ' a droite
  -->Sinon
  --> On applique la largeur de champ avec des ' ' a gauche
  --> Sinon
  --> On applique la precision
  -->S'il y a le flag - 
  --> On applique la largeur de champ avec des '0' a droite
  -->Sinon
  --> On applique la largeur de champ avec des '0' a gauche
  -->S'il y a le flag - et (le flag + ou que nb < 0)
  --> On place le signe (en ecrasant un 0)
  -->Sinon s'il n'y a pas le flag - et que (le flag + ou que nb < 0)
  --> On place le signe (en decallant tout le texte sur la droite)
  }*/

void	ft_f_width_int(t_data *data, long long t)
{
	char	*s;

	if (data->flags->zero != 1)
	{
		if (data->flags->plus == 1 || t < 0)
			data->prs->tmp = ft_strjoin((t < 0 ? "-" : "+"), data->prs->tmp);
		if ((t_ull)data->accu > ((t_ull)ft_strlen(data->prs->tmp) || data->accu == 0))
			ft_accu_int(data);
		if (t >= 0 && data->flags->space == 1)
			data->prs->tmp = ft_strjoin(" ", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		if (data->flags->minus == 1)
		{
			if (!(s = ft_strnew(data->f_width - data->len)))
				return ;
			ft_memset(s, ' ', data->f_width - data->len);
			data->prs->tmp = ft_strjoin(data->prs->tmp, s);
		}
		else
		{
			if (!(s = ft_strnew(data->f_width - data->len)))
				return ;
			ft_memset(s, ' ', data->f_width - data->len);
			data->prs->tmp = ft_strjoin(s, data->prs->tmp);
		}
	}
	else
	{
		if ((t_ull)data->accu > ((t_ull)ft_strlen(data->prs->tmp) || data->accu == 0))
			ft_accu_int(data);
		data->len = ft_strlen(data->prs->tmp);
		if (data->flags->minus)
		{
			if (!(s = ft_strnew(data->f_width - data->len)))
				return ;
			ft_memset(s, '0', data->f_width - data->len);
			data->prs->tmp = ft_strjoin(data->prs->tmp, s);
		}
		else
		{
			if (!(s = ft_strnew(data->f_width - data->len)))
				return ;
			ft_memset(s, '0', data->f_width - data->len);
			data->prs->tmp = ft_strjoin(s, data->prs->tmp);
		}
		if (t >= 0 && data->flags->space == 1 && !(data->flags->plus == 1 || t < 0))
			{
				if (data->f_width > data->len && data->flags->minus != 1)
					data->prs->tmp[0] = ' ';
				else
					data->prs->tmp = ft_strjoind(" ", data->prs->tmp);
				if (data->flags->minus == 1 && data->f_width > data->len)
					data->prs->tmp = ft_strsub(data->prs->tmp, 0, ft_strlen(data->prs->tmp) - 1);
			}
		data->len = ft_strlen(data->prs->tmp);
		if (data->flags->minus != 1 && (data->flags->plus == 1 || t < 0))
		{
			if (data->f_width > 0)
				data->prs->tmp[0] = (t < 0 ? '-' : '+');
			else
				data->prs->tmp = ft_strjoin((t < 0 ? "-" : "+"), data->prs->tmp);
		}
		else if (data->flags->minus == 1 && (data->flags->plus == 1 || t < 0))
		{
			if (data->f_width > 0)
				data->prs->tmp = ft_strsub(ft_strjoin((t < 0 ? "-" : "+"), data->prs->tmp), 0, data->len - 1);
			else
				data->prs->tmp = ft_strjoin((t < 0 ? "-" : "+"), data->prs->tmp);
		}
	}
}
