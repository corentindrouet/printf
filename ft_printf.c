/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/05 14:25:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i[2];
	int		s;
	char	*ptr;

	ptr = "sSpdDioOuUxXcC";
	i[0] = 0;
	i[1] = 0;
	va_start(ap, format);
	while (format[i[0] + i[1]])
	{
		if (format[i[0] + i[1]] == '%')
		{
			write(1, &format[i[1]], i[0]);
			pct_d(ap, ft_strsub(&format[i[1] + i[0] + 1], 0, cont_carac((char*)format, 'd')));
			i[1] = i[0];
			i[0] = 0;
			s = 14;
			while (s == 14)
			{
				s = -1;
				while (ptr[++s])
					if (ptr[s] == format[i[1] + i[0]])
						break ;
				i[1]++;
			}
		}
		else
			i[0]++;
	}
	if (i[0] != 0)
		write(1, &format[i[1]], i[0]);
	va_end(ap);
	return (1);
}

int		cont_carac(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
