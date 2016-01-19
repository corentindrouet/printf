/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 11:25:49 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pct_ss(const char *restrict format, va_list ap)
{
	char	*ptr;
	char	*str;
	int		i;

	ptr = (char*)va_arg(ap, char*);
	if (ptr == NULL)
		str = "(null)";
	else
	{
		str = ft_strnew(ft_strlen(ptr) + 1);
		ft_strcpy(str, ptr);
	}
	if (ft_strchr(format, '.') != NULL)
	{
		i = 0;
		while (format[i] != '.')
			i++;
		i++;
		str = ft_strsub(str, 0, ft_atoi(&format[i]));
	}
	str = aj_decal(&str, format);
	ft_putstr(str);
	return (ft_strlen(str));
}

int			pct_ls(const char *restrict format, va_list ap)
{
	wchar_t	*res;
	int		ow;
	int		i;

	(void)format;
	res = (wchar_t*)va_arg(ap, wchar_t*);
	if (res == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ow = 0;
	i = 0;
	while (res[i] != 0)
		ow += ft_putwchar_t(res[i++]);
	return (ow);
}

int			pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		return (pct_ls(format, ap));
	else
		return (pct_ss(format, ap));
}
