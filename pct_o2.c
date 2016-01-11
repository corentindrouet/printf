/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:42:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/11 10:13:59 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_jo(va_list ap, const char *restrict format, int base)
{
	intmax_t		ptr;
	char			*res;

	ptr = (intmax_t)va_arg(ap, intmax_t);
	res = ft_lltoa_base((long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	ft_putstr(res);
}

void	pct_zo(va_list ap, const char *restrict format, int base)
{
	size_t	ptr;
	char	*res;

	ptr = (size_t)va_arg(ap, size_t);
	res = ft_lltoa_base((long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	ft_putstr(res);
}

void	pct_oo(va_list ap, const char *restrict format, int base)
{
	unsigned int	ptr;
	char			*res;

	ptr = (int)va_arg(ap, int);
	res = ft_itoa_base((int)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	ft_putstr(res);
}
