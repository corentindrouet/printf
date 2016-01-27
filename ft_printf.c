/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:32:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/27 15:04:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	f_init(int (**f)(const char *reformatict, va_list))
{
	f[0] = &pct_s;
	f[1] = &pct_gs;
	f[2] = &pct_p;
	f[3] = &pct_d;
	f[4] = &pct_gd;
	f[5] = &pct_i;
	f[6] = &pct_o;
	f[7] = &pct_go;
	f[8] = &pct_u;
	f[9] = &pct_gu;
	f[10] = &pct_x;
	f[11] = &pct_gx;
	f[12] = &pct_c;
	f[13] = &pct_gc;
	f[14] = &pct_b;
	f[15] = &pct_pct;
}

static int	verif_flag(const char *restrict format, int s, int e, va_list ap)
{
	int		i;
	int		j;
	char	*ptr;
	char	c;

	i = -1;
	while (format[++i] && format[i] != s)
		if (format[i] != '+' && format[i] != '-' && !(format[i] >= '0'
					&& format[i] <= '9') && format[i] != ' ' && format[i] != '#'
				&& format[i] != 'h' && format[i] != 'l' && format[i] != 'j'
				&& format[i] != 'z' && format[i] != '%' && format[i] != '.'
				&& format[i] != '*')
			break ;
	if (e == 1 && format[i] && format[i] != s)
	{
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
	else if (e == 0 && format[i] && format[i] != s)
		return (i);
	return (-1);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i[3];
	int		s;
	char	*ptr;
	int		(*f[16])(const char *restrict, va_list);

	f_init(f);
	ptr = "sSpdDioOuUxXcCbn%";
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	va_start(ap, format);
	while ((i[1] = cont_carac((char*)&format[i[0]], '%')) >= 0)
	{
		print_str_color(ft_strsub(&format[i[0]], 0, i[1]));
		i[2] += i[1];
		i[0] += i[1];
		i[1] = -1;
		s = '\0';
		while (++i[1] < 17)
			if (cont_carac((char*)&format[i[0] + 1], ptr[i[1]]) >= 0)
				if ((cont_carac((char*)&format[i[0] + 1], s) >
							cont_carac((char*)&format[i[0] + 1], ptr[i[1]])))
					s = ptr[i[1]];
		i[1] = 0;
		while (ptr[i[1]] != s && ptr[i[1]])
			i[1]++;
		if (s == 'n')
		{
			pct_n(i[2], ap, ft_strsub(&format[i[0] + 1], 0, cont_carac((char*)&format[i[0] + 1], s) + 1));
			i[0] += cont_carac((char*)&format[i[0]], s) + 1;
		}
		else if (i[1] != 17 && (verif_flag(ft_strsub(&format[i[0] + 1], 0,
							cont_carac((char*)&format[i[0]], s) + 1), s, 0, ap) == -1))
		{
			i[2] += f[i[1]](ft_strsub(&format[i[0] + 1], 0,
						cont_carac((char*)&format[i[0] + 1], s) + 1), ap);
			if (s == '%')
				i[0]++;
			i[0] += cont_carac((char*)&format[i[0]], s) + 1;
		}
		else if (verif_flag(ft_strsub(&format[i[0] + 1], 0,
						cont_carac((char*)&format[i[0]], s) + 1), s, 0, ap) != -1 || i[1] == 17)
		{
			i[2] += verif_flag(ft_strsub(&format[i[0] + 1], 0,
						cont_carac((char*)&format[i[0]], s) + 1), s, 1, ap);
			i[0] += verif_flag(ft_strsub(&format[i[0] + 1], 0,
						cont_carac((char*)&format[i[0]], s) + 1), s, 0, ap) + 2;
		}
	}
	i[2] += ft_strlen(&format[i[0]]);
	print_str_color((char*)&format[i[0]]);
	va_end(ap);
	if (i[2] < 0)
		i[2] = 0;
	return (i[2]);
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
