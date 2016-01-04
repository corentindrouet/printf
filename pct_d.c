/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/04 14:36:02 by cdrouet          ###   ########.fr       */
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
	if (format[ret] == 'h' && format[ret + 1] == 'h')
		pct_hhd(ap);
	else if (format[ret] == 'h')
		pct_hd(ap);
	else if (format[ret] == 'l' && format[ret + 1] == 'l')
		pct_lld(ap);
	else if (format[ret] == 'l')
		pct_ld(ap);
	else if (format[ret] == 'j')
		pct_jd(ap);
	else if (format[ret] == 'z')
		pct_zd(ap);
	else if (format[ret] == 'd')
		pct_dd(ap);
}

void	pct_hhd(va_list ap)
{
	signed char	ptr;
	int			convert;
	char		*res;

	ptr = (signed char)va_arg(ap, int);
	convert = ptr;
	res = ft_itoa(convert);
	write(1, res, ft_strlen(res));
}

void	pct_hd(va_list ap)
{
	short	i;
	char	*res;

	i = (short)va_arg(ap, int);
	res = ft_itoa((int)i);
	write(1, res, ft_strlen(res));
}

void	pct_ld(va_list ap)
{
	long	i;
	char	*res;

	i = va_arg(ap, long);
	res = ft_lltoa((long)i);
	write(1, res, ft_strlen(res));
}

void	pct_lld(va_list ap)
{
	long long	i;
	char		*res;

	i = va_arg(ap, long long);
	res = ft_lltoa(i);
	write(1, res, ft_strlen(res));
}
