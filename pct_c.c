/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:23:01 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/18 13:41:40 by cdrouet          ###   ########.fr       */
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
	if (format[i] && format[i - 1] != '.')
	{
		str = ft_strnew(2);
		str[0] = ptr;
		str = aj_decal(&str, format);
		if (ptr == 0)
		{
			ft_putstr(&str[1]);
			ft_putchar('\0');
		}
		else
			ft_putstr(str);
		if (ft_strlen(str) == 0)
			return (1);
		return (ft_strlen(str));
	}
	ft_putchar(ptr);
	return (1);
}

int			pct_lc(const char *restrict format, va_list ap)
{
	wchar_t	res;

	(void)format;
	res = (wchar_t)va_arg(ap, wchar_t);
	write(1, &res, 1);
	return (1);
}

int			pct_c(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') == NULL)
		return (pct_cc(format, ap));
	return (0);
}
