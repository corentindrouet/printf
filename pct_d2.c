/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 15:10:48 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jd(va_list ap, const char *restrict f)
{
	intmax_t	i;
	char		*r;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, intmax_t);
	if (i >= 0)
		r = ft_lltoa((long long)i);
	else
		r = ft_strsub(ft_lltoa(i), 1, ft_strlen(ft_lltoa(i)) - 1);
	r = precis_d(&r, f, nb2);
	r = plus_d(&r, f, i);
	r = width_d(&r, f, nb1);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else
			r = ft_strjoin(" ", r);
	}
	ft_putstr(r);
	return (ft_strlen(r));
}

int		pct_zd(va_list ap, const char *restrict f)
{
	ssize_t	i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, ssize_t);
	if (i >= 0)
		r = ft_lltoa((long long)i);
	else
		r = ft_strsub(ft_lltoa((long long)i), 1, ft_strlen(ft_lltoa(i)) - 1);
	r = precis_d(&r, f, nb2);
	r = plus_d(&r, f, i);
	r = width_d(&r, f, nb1);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else
			r = ft_strjoin(" ", r);
	}
	ft_putstr(r);
	return (ft_strlen(r));
}

int		pct_dd(va_list ap, const char *restrict f)
{
	int		i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, int);
	if (i >= 0)
		r = ft_itoa(i);
	else
		r = ft_strsub(ft_itoa(i), 1, ft_strlen(ft_itoa(i)) - 1);
	r = precis_d(&r, f, nb2);
	r = plus_d(&r, f, i);
	r = width_d(&r, f, nb1);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else
			r = ft_strjoin(" ", r);
	}
	ft_putstr(r);
	return (ft_strlen(r));
}

char	*aj_plus(char **ptr, const char *restrict format, int j)
{
	char	*res;
	int		i;

	i = ft_atoi(ft_strchr(format, '.') + 1) + (int)ft_strlen(ft_itoa(j));
	if (ft_atoi(*ptr) != 0 || !ft_strchr(format, '.')
		|| (ft_strchr(format, '.') && i != (int)ft_strlen(*ptr)))
	{
		i = -1;
		while ((*ptr)[++i])
			if ((*ptr)[i] == '0' && (*ptr)[i + 1])
			{
				(*ptr)[i] = '+';
				return (*ptr);
			}
		i = -1;
		while ((*ptr)[++i] == ' ')
			if ((*ptr)[i + 1] != ' ' && (*ptr)[i + 1])
			{
				(*ptr)[i] = '+';
				return (*ptr);
			}
	}
	res = (char*)malloc(ft_strlen(*ptr) + 2);
	i = ft_strlen(*ptr);
	res[i + 1] = '\0';
	while (--i >= 0)
		res[i + 1] = (*ptr)[i];
	res[0] = '+';
	free(*ptr);
	return (res);
}
