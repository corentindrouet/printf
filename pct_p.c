/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:56:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/25 08:24:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_p(const char *restrict format, va_list ap)
{
	void	*ptr;
	char	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (void*)va_arg(ap, void*);
	res = ft_strnew(1);
	res = ft_strjoin(res, ft_lltoa_base((long long)ptr, 16));
	res = aj_zero(&res, format, nb2);
	res = ft_strjoin("0x", res);
	res = aj_decal(&res, format, nb1);
	ft_putstr(res);
	return (ft_strlen(res));
}
