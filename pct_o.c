/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:58:40 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/18 08:34:50 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_o(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		return (pct_hho(ap, format, 8, 0));
	else if (ft_strchr(format, 'h') != NULL)
		return (pct_ho(ap, format, 8, 0));
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		return (pct_llo(ap, format, 8, 0));
	else if (ft_strchr(format, 'l'))
		return (pct_lo(ap, format, 8, 0));
	else if (ft_strchr(format, 'j'))
		return (pct_jo(ap, format, 8, 0));
	else if (ft_strchr(format, 'z'))
		return (pct_zo(ap, format, 8, 0));
	else
		return (pct_oo(ap, format, 8, 0));
}

int		pct_hho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned char	ptr;
	char			*res;

	ptr = (unsigned char)va_arg(ap, int);
	res = ft_itoa_base(ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_ho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned short	ptr;
	char			*res;

	ptr = (unsigned short)va_arg(ap, int);
	res = ft_itoa_base(ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_llo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long long	ptr;
	char				*res;

	ptr = (unsigned long long)va_arg(ap, unsigned long long);
	res = ft_ulltoa_base((unsigned long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_lo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long	ptr;
	char			*res;

	ptr = (unsigned long)va_arg(ap, unsigned long);
	res = ft_ultoa_base((unsigned long)ptr, base);
	if (ft_strchr(format, '#') == NULL)
		res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}
