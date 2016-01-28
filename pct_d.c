/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/28 13:31:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_d(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		return (pct_hhd(ap, format));
	else if (ft_strchr(format, 'h') != NULL)
		return (pct_hd(ap, format));
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		return (pct_lld(ap, format));
	else if (ft_strchr(format, 'l'))
		return (pct_ld(ap, format));
	else if (ft_strchr(format, 'j'))
		return (pct_jd(ap, format));
	else if (ft_strchr(format, 'z'))
		return (pct_zd(ap, format));
	else
		return (pct_dd(ap, format));
}

int		pct_hhd(va_list ap, const char *restrict format)
{
	signed char	ptr;
	char		*res;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	ptr = (signed char)va_arg(ap, int);
	res = ft_itoa((int)ptr);
	res = aj_zero(&res, format, nb2);
	res = aj_decal(&res, format, nb1);
	if (ptr >= 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (ptr > 0 && (ft_strchr(format, '+') == NULL)
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

int		pct_hd(va_list ap, const char *restrict format)
{
	short	i;
	char	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = (short)va_arg(ap, int);
	res = ft_itoa((int)i);
	res = aj_zero(&res, format, nb2);
	res = aj_decal(&res, format, nb1);
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

int		pct_ld(va_list ap, const char *restrict format)
{
	long	i;
	char	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, long);
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

int		pct_lld(va_list ap, const char *restrict format)
{
	long long	i;
	char		*res;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, format);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, long long);
	res = ft_lltoa(i);
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
