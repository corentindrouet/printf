/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:42:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/12 08:11:13 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_jo(va_list ap, const char *restrict format, int base, int maj)
{
	intmax_t		ptr;
	char			*res;

	ptr = (intmax_t)va_arg(ap, intmax_t);
	res = ft_lltoa_base((long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	pct_zo(va_list ap, const char *restrict format, int base, int maj)
{
	size_t	ptr;
	char	*res;

	ptr = (size_t)va_arg(ap, size_t);
	res = ft_lltoa_base((long long)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	pct_oo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned int	ptr;
	char			*res;

	ptr = (int)va_arg(ap, int);
	res = ft_itoa_base((int)ptr, base);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	ft_putstr(res);
}

void	ft_strtoupper(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
}
