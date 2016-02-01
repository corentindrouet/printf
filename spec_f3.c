/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:42:40 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 10:08:16 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nopct(const char *restrict format, int i, va_list ap)
{
	char	c;
	char	*ptr;
	int		j;

	c = format[i];
	j = 0;
	while (format[j] && !ft_isdigit(format[j]) && format[j] != '*')
		j++;
	if (format[j])
	{
		if (format[j] == '*')
			init(&i, &j, ap);
		ptr = ft_strnew(2);
		ptr[0] = c;
		ptr = aj_decal(&ptr, format, j);
		ft_putstr(ptr);
		return (ft_strlen(ptr));
	}
	else
		ft_putchar(c);
	return (1);
}

int			cont_carac(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
		if (s[i++] == '\0')
			return (-1);
	return (i);
}

int			pct_pct(const char *restrict format, va_list ap)
{
	char	*res;

	(void)ap;
	res = ft_strnew(2);
	res[0] = '%';
	res = aj_decal(&res, format, 0);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			verif_flag(const char *restrict format, int s, int e, va_list ap)
{
	int		i;

	i = -1;
	while (format[++i] && format[i] != s)
		if (format[i] != '+' && format[i] != '-' && !(format[i] >= '0'
					&& format[i] <= '9') && format[i] != ' ' && format[i] != '#'
				&& format[i] != 'h' && format[i] != 'l' && format[i] != 'j'
				&& format[i] != 'z' && format[i] != '%' && format[i] != '.'
				&& format[i] != '*')
			break ;
	if (e == 1 && format[i] && format[i] != s)
		return (print_nopct(format, i, ap));
	else if (e == 0 && format[i] && format[i] != s)
		return (i);
	return (-1);
}
