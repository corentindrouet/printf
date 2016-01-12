/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:58:40 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/12 08:11:45 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_o(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		pct_hho(ap, format, 8, 0);
	else if (ft_strchr(format, 'h') != NULL)
		pct_ho(ap, format, 8, 0);
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		pct_llo(ap, format, 8, 0);
	else if (ft_strchr(format, 'l'))
		pct_lo(ap, format, 8, 0);
	else if (ft_strchr(format, 'j'))
		pct_jo(ap, format, 8, 0);
	else if (ft_strchr(format, 'z'))
		pct_zo(ap, format, 8, 0);
	else
		pct_oo(ap, format, 8, 0);
}

void	pct_hho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned char	ptr;
	char			*res;

	ptr = (unsigned char)va_arg(ap, int);
	res = ft_ctoa_base((unsigned char)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	pct_ho(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned short	ptr;
	char			*res;

	ptr = (unsigned short)va_arg(ap, int);
	res = ft_stoa_base((unsigned short)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	pct_llo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long long	ptr;
	char				*res;

	ptr = (unsigned long long)va_arg(ap, unsigned long long);
	res = ft_lltoa_base((unsigned long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	pct_lo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned long	ptr;
	char			*res;

	ptr = (unsigned long)va_arg(ap, unsigned long);
	res = ft_ltoa_base((unsigned long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}
