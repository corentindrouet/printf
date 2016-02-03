/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decal_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:21:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 15:08:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precis_d(char **ptr, const char *restrict format, int nbr)
{
	int		precision;
	int		i;
	char	*res;

	if (ft_strchr(format, '.'))
	{
		if (!ft_strchr(ft_strchr(format, '.'), '*'))
			precision = ft_atoi(ft_strchr(format, '.') + 1);
		else
			precision = nbr;
	}
	else
		return (*ptr);
	if (precision == 0 && ft_atoi(*ptr) == 0)
		(*ptr)[0] = '\0';
	if (precision <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(precision + 1);
	i = -1;
	while (++i < (precision - (int)ft_strlen(*ptr)))
		res[i] = '0';
	res = ft_strcat(res, *ptr);
	return (res);
}

char	*plus_d(char **ptr, const char *restrict format, long long i)
{
	if (!ft_strchr(format, '+') && i >= 0)
		return (*ptr);
	if (i >= 0)
		return (ft_strjoin("+", *ptr));
	return (ft_strjoin("-", *ptr));
}

char	*width_d(char **ptr, const char *restrict format, int nbr)
{
	int		i;
	int		wid;
	char	*res;
	char	c;

	i = -1;
	c = ' ';
	while (!(format[++i] > '0' && format[i] <= '9') && format[i] != '*')
		if (!format[i] || format[i] == '.')
			return (*ptr);
		else if (format[i] == '0' && !ft_strchr(format, '.')
			&& !ft_strchr(format, '-'))
			c = '0';
	if (format[i] == '*')
		wid = nbr;
	else
		wid = ft_atoi(&format[i]);
	if (wid <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(wid - ft_strlen(*ptr) + 1);
	i = -1;
	while (++i < (wid - (int)ft_strlen(*ptr)))
		res[i] = c;
	if (c == '0' && ((*ptr)[0] == '+' || (*ptr)[0] == '-'))
		return (ft_strjoin(ft_strsub(*ptr, 0, 1), ft_strjoin(res, &(*ptr)[1])));
	else if (c == '0' || !ft_strchr(format, '-'))
		return (ft_strjoin(res, *ptr));
	else
		return (ft_strjoin(*ptr, res));
}
