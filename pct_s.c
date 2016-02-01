/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 14:09:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pct_ss2(const char *restrict format, int nb2, int nb1, char *ptr)
{
	char	*str;
	int		i;

	if (ptr == NULL)
		str = ft_strjoin("(nu", "ll)");
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
		if (nb2 < 0)
			nb2 *= -1;
		if (format[i] != '*')
			str = ft_strsub(str, 0, ft_atoi(&format[i]));
		else
			str = ft_strsub(str, 0, nb2);
	}
	str = aj_decal(&str, format, nb1);
	return (str);
}

static int	pct_ss(const char *restrict format, va_list ap)
{
	char	*ptr;
	char	*str;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (char*)va_arg(ap, char*);
	str = pct_ss2(format, nb2, nb1, ptr);
	ft_putstr(str);
	return (ft_strlen(str));
}

int			pct_ls(const char *restrict format, va_list ap)
{
	wchar_t	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	res = (wchar_t*)va_arg(ap, wchar_t*);
	if (res == NULL)
		return (ft_putwstr_t(L"(null)"));
	res = precis_wchar_t(res, format, (int)nb2);
	res = decal_wstr(&res, format, (int)nb1);
	return (ft_putwstr_t(res));
}

int			pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		return (pct_ls(format, ap));
	else
		return (pct_ss(format, ap));
}
