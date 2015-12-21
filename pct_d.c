/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/21 15:31:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_d(va_list ap, char *c, int *d)
{
	int		ret;
	char	*str;
	char	*longstr;

	ret = va_arg(ap, int);
	str = ft_itoa(ret);
	longstr = ft_strnew(d[0] + 15);
	ft_strcpy(longstr, str);
	if (c[0] != -1)
	{
		if (c[0] == '+')
			ft_plus(longstr, d[0]);
		if (c[0] == '-')
			ft_moin(longstr, d[0]);
	}
	ft_putstr(longstr);
	ft_strdel(&longstr);
}
