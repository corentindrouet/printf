/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/05 08:40:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_jd(va_list ap, const char *restrict format)
{
	intmax_t	i;
	char		*res;

	i = va_arg(ap, intmax_t);
	res = ft_lltoa((long long)i);
	ft_putstr(res);
}

void	pct_zd(va_list ap, const char *restrict format)
{
	ssize_t	i;
	char	*res;

	i = va_arg(ap, size_t);
	res = ft_lltoa((long long)i);
	ft_putstr(res);
}

void	pct_dd(va_list ap, const char *restrict format)
{
	int		i;
	char	*res;

	i = va_arg(ap, int);
	res = ft_itoa(i);
	if (i > 0 && (ft_strchr(format) != NULL))
		res = aj_plus(&res);
	ft_putstr(res);
}

char	*aj_plus(char **ptr)
{
	char	*res;
	int		i;

	res = (char*)malloc(ft_strlen(*ptr) + 2);
	i = ft_strlen(*ptr) - 1;
	res[i + 2] = '\0';
	while (i >= 0)
	{
		res[i + 1] = (*ptr)[i];
		i--;
	}
	res[0] = '+';
	free(*ptr);
	return (res);
}
