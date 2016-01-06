/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/06 15:38:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_init(void (**f)(va_list, const char *restrict))
{
	int	i;

	i = -1;
/*	f[++i] = &pct_s;
	f[++i] = &pct_S;
	f[++i] = &pct_p;
*/	f[++i] = &pct_d;
/*	f[++i] = &pct_D;
	f[++i] = &pct_i;
	f[++i] = &pct_o;
	f[++i] = &pct_O;
	f[++i] = &pct_u;
	f[++i] = &pct_U;
	f[++i] = &pct_x;
	f[++i] = &pct_X;
	f[++i] = &pct_c;
	f[++i] = &pct_C;*/
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i[2];
	int		s;
	char	*ptr;
	void	(*f[14])(va_list, const char *restrict);

	f_init(f);
//	ptr = "sSpdDioOuUxXcC";
	ptr = "dDioOuUxXcCsSp";
	i[0] = 0;
	i[1] = 0;
	va_start(ap, format);
//			pct_d(ap, ft_strsub(&format[i[1] + i[0] + 1], 0, cont_carac((char*)&format[i[1] + i[0] + 1], 'd')));
	while ((i[1] = cont_carac((char*)&format[i[0]], '%') >= 0))
	{
		write(1, &format[i[0]], i[1]);
		i[0] += i[1];
		i[1] = 0;
		while ()
	}
	va_end(ap);
	return (1);
}

int		cont_carac(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
		if (!s[i++])
			return (-1);
	return (i);
}
