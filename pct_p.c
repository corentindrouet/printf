/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:56:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/26 11:18:47 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_p(const char *restrict format, va_list ap)
{
//	void	*ptr;
	char	*res;
/*	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	res = ft_strnew(1);
	res = ft_strjoin(res, ft_lltoa_base((long long)ptr, 16));
	res = aj_zero(&res, format, nb2);
	res = ft_strjoin("0x", res);
	res = aj_decal(&res, format, nb1);*/
	res = ft_strnew(1);
	res = ft_strjoin("#", ft_strsub(format, 0, ft_strlen(format) - 1));
	res = ft_strcat(res, "lxp");
	return (pct_x(res, ap));
}
