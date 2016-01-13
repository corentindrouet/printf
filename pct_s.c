/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 08:50:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pct_ss(const char *restrict format, va_list ap)
{
	char	*ptr;
	int		i;

	ptr = (char*)va_arg(ap, char*);
	if (ptr == NULL)
		ptr = "(null)";
	if (ft_strchr(format, '.') != NULL)
	{
		i = 0;
		while (format[i] != '.')
			i++;
		i++;
		ptr = ft_strsub(ptr, 0, ft_atoi(&format[i]));
	}
	ptr = aj_decal(&ptr, format);
	ft_putstr(ptr);
	return (ft_strlen(ptr));
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
