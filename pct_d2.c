/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 14:45:14 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jd(va_list ap, const char *restrict format)
{
	intmax_t	i;
	char		*res;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, intmax_t);
	res = ft_lltoa((long long)i);
	res = aj_zero(&res, format, nb2);
	res = aj_decal(&res, format, nb1);
	if (i >= 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
	{
		if (res[0] == '0')
			res[0] = ' ';
		else
			res = ft_strjoin(" ", res);
	}
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_zd(va_list ap, const char *restrict format)
{
	ssize_t	i;
	char	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, size_t);
	res = ft_lltoa((long long)i);
	res = aj_zero(&res, format, (int)nb2);
	res = aj_decal(&res, format, (int)nb1);
	if (i >= 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
	{
		if (res[0] == '0')
			res[0] = ' ';
		else
			res = ft_strjoin(" ", res);
	}
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_dd(va_list ap, const char *restrict format)
{
	int		i;
	char	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, int);
	res = ft_itoa(i);
	res = aj_zero(&res, format, (int)nb2);
	res = aj_decal(&res, format, (int)nb1);
	if (i >= 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i >= 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
	{
		if (res[0] == '0')
			res[0] = ' ';
		else
			res = ft_strjoin(" ", res);
	}
	ft_putstr(res);
	return (ft_strlen(res));
}

char	*aj_plus(char **ptr)
{
	char	*res;
	int		i;

	i = -1;
	while ((*ptr)[++i])
		if ((*ptr)[i] == '0' && (*ptr)[i + 1])
		{
			(*ptr)[i] = '+';
			return (*ptr);
		}
	i = -1;
	while ((*ptr)[++i] == ' ')
		if ((*ptr)[i + 1] != ' ')
		{
			(*ptr)[i] = '+';
			return (*ptr);
		}
	res = (char*)malloc(ft_strlen(*ptr) + 2);
	i = ft_strlen(*ptr) - 1;
	res[i + 2] = '\0';
	i++;
	while (--i >= 0)
		res[i + 1] = (*ptr)[i];
	res[0] = '+';
	free(*ptr);
	return (res);
}
