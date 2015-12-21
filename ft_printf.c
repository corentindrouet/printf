/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/21 15:54:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	c[3];
	int		d[2];
	char	ptr[15] = "sSpdDioOuUxXcC";
	void	(*f)(va_list, char*, int*);

	f = &pct_d;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			write(1, "%", 1);
		else if (format[i] == '%')
		{
			i++;
			if ((c[0] = verif_flag(&format[i])) != -1)
				i++;
			if ((d[0] = verif_width(&format[i])) != -1)
			{
				j = d[0];
				while (j > 0)
				{
					j = j / 10;
					i++;
				}
			}
			if ((d[1] = verif_precision(&format[i + 1])) != -1)
			{
				j = d[1];
				while (j > 0)
				{
					j = j / 10;
					i++;
				}
			}
			if ((c[1] = verif_lenght(&format[i])) != -1)
				i++;
			if ((c[2] = verif_spec(&format[i])) != -1)
			{
				j = 0;
				while (ptr[j] && ptr[j] != c[2])
					j++;
				pct_d(ap, c, d);
			}
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (1);
}
