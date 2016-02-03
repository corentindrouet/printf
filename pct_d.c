/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 08:15:32 by cdrouet          ###   ########.fr       */
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
	signed char	ptr;
	char		*r;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	ptr = (signed char)va_arg(ap, int);
	r = ft_itoa((int)ptr);
	r = aj_zero(&r, f, nb2);
	r = aj_decal(&r, f, nb1);
	if (ptr >= 0 && (ft_strchr(f, '+') != NULL))
		r = aj_plus(&r);
	else if (ptr >= 0 && (ft_strchr(f, '+') == NULL)
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
	r = ft_itoa((int)i);
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
	r = ft_lltoa(i);
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
