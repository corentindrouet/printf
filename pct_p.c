/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:56:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/21 14:40:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_p(const char *restrict format, va_list ap)
{
	void	*ptr;
	char	*res;

	ptr = (void*)va_arg(ap, void*);
	res = ft_strnew(1);
	res = ft_strjoin(res, ft_lltoa_base((long long)ptr, 16));
	res = aj_zero(&res, format);
	res = ft_strjoin("0x", res);
	res = aj_decal(&res, format);
	ft_putstr(res);
	return (ft_strlen(res));
}
