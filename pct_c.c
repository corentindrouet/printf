/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:23:01 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/14 08:58:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pct_cc(const char *restrict format, va_list ap)
{
	char	ptr;
	char	*str;
	int		i;

	ptr = (char)va_arg(ap, int);
	i = 0;
	while (format[i] && !ft_isdigit(format[i]))
		i++;
	if (format[i])
	{
		str = ft_strnew(2);
		str[0] = ptr;
		str = aj_decal(&str, format);
		ft_putstr(str);
		return (ft_strlen(str));
	}
	ft_putchar(ptr);
	return (1);
}

int			pct_c(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') == NULL)
		return (pct_cc(format, ap));
	return (0);
}
