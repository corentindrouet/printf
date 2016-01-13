/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:01:57 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 10:45:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*aj_zero_pos(char **ptr, const char *restrict format, int i)
{
	char	*res;
	int		l;

	l = 0;
	if (i <= (int)ft_strlen(*ptr))
		return (*ptr);
	if (ft_strchr(format, '+') != NULL)
		i++;
	res = (char*)ft_strnew(sizeof(char) * (i + 1));
	while (l < (i - (int)ft_strlen(*ptr)))
		res[l++] = '0';
	ft_strcpy(&res[l], *ptr);
	free(*ptr);
	return (res);
}

static char	*aj_zero_neg(char **ptr, int i)
{
	char	*res;
	int		l;

	l = 0;
	if (i < (int)ft_strlen(*ptr))
		return (*ptr);
	res = (char*)ft_strnew(sizeof(char) * (i + 2));
	res[l++] = '-';
	while (l <= (i - (int)ft_strlen(*ptr) + 1))
		res[l++] = '0';
	ft_strcpy(&res[l], &(*ptr)[1]);
	free(*ptr);
	return (res);
}

char	*aj_zero(char **ptr, const char *restrict format)
{
	int		i;

	i = -1;
	while (format[++i] != '.')
		if (!format[i])
			return (*ptr);
	i = ft_atoi(&format[++i]);
	if (i == 0 && ft_atoi(*ptr) == 0)
		(*ptr)[0] = '\0';
	if (ft_atoi(*ptr) < 0)
		return (aj_zero_neg(ptr, i));
	else
		return (aj_zero_pos(ptr, format, i));
}

void	aj_decal_d(int i, char **ptr, char *res, char c)
{
	int	j;

	j = ft_strlen(*ptr);
	j--;
	while (j >= 0)
		res[i--] = (*ptr)[j--];
	while (i >= 0)
		res[i--] = c;
}

void	aj_decal_g(int i, const char *restrict format, char *res, char **ptr)
{
	int	j;

	j = ft_strlen(*ptr);
	ft_strcpy(res, *ptr);
	if (ft_strchr(format, '+') != NULL)
		i--;
	while (j < (i + 1))
		res[j++] = ' ';
}
