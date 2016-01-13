/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:56:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 08:58:50 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_p(const char *restrict format, va_list ap)
{
	void	*ptr;
	char	*res;

	ptr = (void*)va_arg(ap, void*);

	res = "0x";
	res = ft_strjoin(res, ft_lltoa_base((long long)ptr, 16));
	res = aj_decal(&res, format);
	ft_putstr(res);
	return (ft_strlen(res));
}
