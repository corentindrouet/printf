/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:39:15 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/17 15:47:59 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_d(va_list ap, char *c, int *d)
{
	int	ret;

	(void)d;
	ret = va_arg(ap, int);
	if (c[0] != -1)
	{
		if (ret >= 0 && c[0] == '+')
			ft_putchar('+');
		if (c[0] == ' ')
			ft_putchar(' ');
	}
	ft_putnbr(ret);
}
