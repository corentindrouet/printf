/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:22:36 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/11 10:17:58 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_x(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		pct_hho(ap, format, 16);
	else if (ft_strchr(format, 'h') != NULL)
		pct_ho(ap, format, 16);
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		pct_llo(ap, format, 16);
	else if (ft_strchr(format, 'l'))
		pct_lo(ap, format, 16);
	else if (ft_strchr(format, 'j'))
		pct_jo(ap, format, 16);
	else if (ft_strchr(format, 'z'))
		pct_zo(ap, format, 16);
	else
		pct_oo(ap, format, 16);
}
