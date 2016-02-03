/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 15:14:35 by cdrouet          ###   ########.fr       */
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

int		pct_hhd(va_list ap, const char *restrict f)
{
	signed char	i;
	char		*r;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = (signed char)va_arg(ap, int);
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

int		pct_hd(va_list ap, const char *restrict f)
{
	short	i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = (short)va_arg(ap, int);
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

int		pct_ld(va_list ap, const char *restrict f)
{
	long	i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, long);
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

int		pct_lld(va_list ap, const char *restrict f)
{
	long long	i;
	char		*r;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, long long);
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
