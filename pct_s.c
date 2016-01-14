/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/14 15:00:18 by cdrouet          ###   ########.fr       */
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

static int	pct_ls(const char *restrict format, va_list ap)
{
	(void)format;
	(void)ap;
	return (0);
}

int			pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		return (pct_ls(format, ap));
	else
		return (pct_ss(format, ap));
}
