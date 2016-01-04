/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/04 10:26:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_d(va_list ap, const char *restrict format)
{
	int		ret;
	int		i;
	char	*ptr;

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
	if (format[i] == 'h' && format[i + 1] == 'h')
		pct_hhd(ap);
	else if (format[i] == 'h')
		pct_hd(ap);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		pct_lld(ap);
	else if (format[i] == 'l')
		pct_ld(ap);
	else if (format[i] == 'j')
		pct_jd(ap);
	else if (format[i] == 'z')
		pct_zd(ap);
	else if (format[i] == 'd')
		pct_dd(ap);
}

void	pct_hhd(va_list ap)
{
	signed char	ptr;

	ptr = va_arg(ap, signed char);
}

void	pct_hd(va_list ap)
{
	short	i;

	i = va_arg(ap, short)
}

void	pct_ld(va_list ap)
{
	long	i;

	i = va_arg(ap, long);
}

void	pct_lld(va_list ap)
{
	long long	i;

	i = va_arg(ap, long long);
}
