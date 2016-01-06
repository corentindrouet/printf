/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/06 15:38:15 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_d(va_list ap, const char *restrict format)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		pct_hhd(ap, format);
	else if (ft_strchr(format, 'h') != NULL)
		pct_hd(ap, format);
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		pct_lld(ap, format);
	else if (ft_strchr(format, 'l'))
		pct_ld(ap, format);
	else if (ft_strchr(format, 'j'))
		pct_jd(ap, format);
	else if (ft_strchr(format, 'z'))
		pct_zd(ap, format);
	else
		pct_dd(ap, format);
}

void	pct_hhd(va_list ap, const char *restrict format)
{
	signed char	ptr;
	int			convert;
	char		*res;

	ptr = (signed char)va_arg(ap, int);
	convert = ptr;
	res = ft_itoa(convert);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (ptr > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (ptr > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
}

void	pct_hd(va_list ap, const char *restrict format)
{
	short	i;
	char	*res;

	i = (short)va_arg(ap, int);
	res = ft_itoa((int)i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
}

void	pct_ld(va_list ap, const char *restrict format)
{
	long	i;
	char	*res;

	i = va_arg(ap, long);
	res = ft_lltoa((long long)i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
}

void	pct_lld(va_list ap, const char *restrict format)
{
	long long	i;
	char		*res;

	i = va_arg(ap, long long);
	res = ft_lltoa(i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
}
