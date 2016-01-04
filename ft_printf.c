/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/04 13:01:44 by cdrouet          ###   ########.fr       */
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
			pct_d(ap, &format[i[1] + i[0] + 1]);
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
