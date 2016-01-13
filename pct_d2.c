/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 08:07:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jd(va_list ap, const char *restrict format)
{
	intmax_t	i;
	char		*res;

	i = va_arg(ap, intmax_t);
	res = ft_lltoa((long long)i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_zd(va_list ap, const char *restrict format)
{
	ssize_t	i;
	char	*res;

	i = va_arg(ap, size_t);
	res = ft_lltoa((long long)i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
	return (ft_strlen(res));
}

int		pct_dd(va_list ap, const char *restrict format)
{
	int		i;
	char	*res;

	i = va_arg(ap, int);
	res = ft_itoa(i);
	res = aj_zero(&res, format);
	res = aj_decal(&res, format);
	if (i > 0 && (ft_strchr(format, '+') != NULL))
		res = aj_plus(&res);
	else if (i > 0 && (ft_strchr(format, '+') == NULL)
		&& (ft_strchr(format, ' ') != NULL))
		ft_putchar(' ');
	ft_putstr(res);
	return (ft_strlen(res));
}

char	*aj_plus(char **ptr)
{
	char	*res;
	int		i;

	if ((*ptr)[0] == '0')
	{
		(*ptr)[0] = '+';
		return (*ptr);
	}
	if ((*ptr)[0] == ' ')
	{
		i = 0;
		while ((*ptr)[i] == ' ')
			i++;
		(*ptr)[i - 1] = '+';
		return (*ptr);
	}
	res = (char*)malloc(ft_strlen(*ptr) + 2);
	i = ft_strlen(*ptr) - 1;
	res[i + 2] = '\0';
	i++;
	while (--i >= 0)
		res[i + 1] = (*ptr)[i];
	res[0] = '+';
	free(*ptr);
	return (res);
}

char	*aj_decal(char **ptr, const char *restrict format)
{
	int		i;
	int		j;
	char	*res;
	char	c;

	i = -1;
	c = ' ';
	j = ft_strlen(*ptr);
	while (format[++i] < '0' || format[i] > '9')
		if (!format[i])
			return (*ptr);
	if (format[i - 1] == '.')
		return (*ptr);
	if (format[i] == '0' && ft_strchr(&format[i], '.') == NULL)
		c = '0';
	i = ft_atoi(&format[i]);
	if (i <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(sizeof(char) * (i + 1));
	if (ft_strchr(format, '-') == NULL)
		aj_decal_d(--i, ptr, res, c);
	else
		aj_decal_g(--i, format, res, ptr);
	free(*ptr);
	return (res);
}
