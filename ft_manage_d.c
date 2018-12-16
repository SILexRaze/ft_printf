#include "ft_printf.h"
#include <stdio.h>
void	ft_manage_int(t_data *data, long long t)
{
	if (t >= 0 && data->flags->space == 1 
			&& (size_t)data->f_width >= ft_strlen(data->prs->tmp))
		data->prs->tmp = ft_strjoind(" ", data->prs->tmp);
	if (t >= 0 && data->flags->plus == 1)
	{
		if (data->flags->space == 1)
			data->prs->tmp[0] = '+';
		else
			data->prs->tmp = ft_strjoind("+", data->prs->tmp);
	}
	ft_f_width(data, ft_strlen(data->prs->tmp));
//	printf("|%s|\n", data->prs->tmp);
	if (t < 0 || data->flags->plus == 1)
		ft_place_sign(data->prs->tmp, data);
}

void	ft_place_sign(char *s, t_data *data)
{
	int i;
	char sign;

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
	if (i < 0)
	{
		data->prs->tmp = ft_strjoind("-", data->prs->tmp);
		i = 0;
	}
	s[i] = sign;
}

int	ft_strchr_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-')
			return (i);
		i++;
	}
	return (0);
}
