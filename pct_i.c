/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:58:17 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 10:11:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pct_i(const char *restrict format, va_list ap)
{
	char	*str;

	str = ft_strchr(format, 'i');
	str[0] = 'd';
	pct_d(format, ap);
}
