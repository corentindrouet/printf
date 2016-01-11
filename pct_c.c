/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:23:01 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/11 11:44:13 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pct_cc(const char *restrict format, va_list ap)
{
	char	ptr;
	char	*str;
	int		i;

	ptr = (char)va_arg(ap, char*);
	i = 0;
	while (format[i] && !ft_isdigit(format[i]))
		i++;
	if (format[i])
	{
		str = ft_strnew(2);
		str[0] = ptr;
		str = aj_decal(&str, format);
		ft_putstr(str);
	}
	else
		ft_putchar(ptr);
}

void		pct_c(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') == NULL)
		pct_cc(format, ap);
}
