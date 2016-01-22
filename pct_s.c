/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/22 14:31:03 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pct_ss(const char *restrict format, va_list ap)
{
	char	*ptr;
	char	*str;
	int		i;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = 0;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (char*)va_arg(ap, char*);
	if (ptr == NULL)
	{
		str = ft_strnew(7);
		str = ft_strcpy(str, "(null)");
	}
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
	str = aj_decal(&str, format, nb1);
	ft_putstr(str);
	return (ft_strlen(str));
}

int			pct_ls(const char *restrict format, va_list ap)
{
	wchar_t	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = 0;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	res = (wchar_t*)va_arg(ap, wchar_t*);
	if (res == NULL)
		return (ft_putwstr_t(L"(null)"));
	res = precis_wchar_t(res, format, nb2);
	res = decal_wstr(&res, format, nb1);
	return (ft_putwstr_t(res));
}

int			pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		return (pct_ls(format, ap));
	else
		return (pct_ss(format, ap));
}
