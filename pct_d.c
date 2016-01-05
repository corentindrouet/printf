/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/05 11:47:30 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_d(va_list ap, const char *restrict format)
{
	int		ret;
	int		i;
	char	*ptr;
	char	*str;

	str = ft_strnew(25);
	ptr = "hljzd";
	i = 5;
	ret = -1;
	while (i == 5)
	{
		i = 0;
		ret++;
		while (format[ret] != ptr[i])
			i++;
	}
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
	if (ptr > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	ft_putstr(res);
}

void	pct_hd(va_list ap, const char *restrict format)
{
	short	i;
	char	*res;

	i = (short)va_arg(ap, int);
	res = ft_itoa((int)i);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	ft_putstr(res);
}

void	pct_ld(va_list ap, const char *restrict format)
{
	long	i;
	char	*res;

	i = va_arg(ap, long);
	res = ft_lltoa((long long)i);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	ft_putstr(res);
}

void	pct_lld(va_list ap, const char *restrict format)
{
	long long	i;
	char		*res;

	i = va_arg(ap, long long);
	res = ft_lltoa(i);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	ft_putstr(res);
}
