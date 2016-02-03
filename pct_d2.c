/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 11:54:38 by cdrouet          ###   ########.fr       */
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
	r = ft_lltoa((long long)i);
	r = aj_zero(&r, f, nb2);
	r = aj_decal(&r, f, nb1);
	if (i >= 0 && (ft_strchr(f, '+') != NULL))
		r = aj_plus(&r);
	else if (i >= 0 && (ft_strchr(f, '+') == NULL)
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
	i = va_arg(ap, size_t);
	r = ft_lltoa((long long)i);
	r = aj_zero(&r, f, (int)nb2);
	r = aj_decal(&r, f, (int)nb1);
	if (i >= 0 && (ft_strchr(f, '+') != NULL))
		r = aj_plus(&r);
	else if (i >= 0 && (ft_strchr(f, '+') == NULL)
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
	r = ft_itoa(i);
	r = aj_zero(&r, f, (int)nb2);
	r = aj_decal(&r, f, (int)nb1);
	if (i >= 0 && (ft_strchr(f, '+') != NULL))
		r = aj_plus(&r);
	else if (i >= 0 && (ft_strchr(f, '+') == NULL)
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
		if ((*ptr)[i + 1] != ' ' && (*ptr)[i + 1])
		{
			(*ptr)[i] = '+';
			return (*ptr);
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
