/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_o2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:42:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/18 10:03:26 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jo(va_list ap, const char *restrict format, int base, int maj)
{
	intmax_t		ptr;
	char			*res;

	ptr = (intmax_t)va_arg(ap, intmax_t);
	res = ft_ulltoa_base((long long)ptr, base);
	if (!(ft_strchr(format, '#') && ptr == 0) || base == 16)
		res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_zo(va_list ap, const char *restrict format, int base, int maj)
{
	size_t	ptr;
	char	*res;

	ptr = (size_t)va_arg(ap, size_t);
	res = ft_ulltoa_base((long long)ptr, base);
	if (!(ft_strchr(format, '#') && ptr == 0) || base == 16)
		res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_oo(va_list ap, const char *restrict format, int base, int maj)
{
	unsigned int	ptr;
	char			*res;

	ptr = (unsigned int)va_arg(ap, unsigned int);
	res = ft_uitoa_base((unsigned int)ptr, base);
	if (!(ft_strchr(format, '#') && ptr == 0) || base == 16)
		res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (base > 10 && maj == 1)
		ft_strtoupper(res);
	if (ft_strchr(format, '#') != NULL)
		res = ft_diese(format, &res, base, maj);
	ft_putstr(res);
	return (ft_strlen(res));
}

void	ft_strtoupper(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
}
