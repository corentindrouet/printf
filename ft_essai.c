/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_essai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:03:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/21 14:25:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precis_str(char **ptr, const char *restrict format)
{
	int		i;
	int		pre;
	char	*res;

	i = -1;
	while (format[++i] != '.')
		if (!format[i])
			return (*ptr);
	pre = ft_atoi(&format[++i]);
	i = 0;
	if ((*ptr)[i] == '-')
		i++;
	if (ft_strlen(&(*ptr)[i]) >= pre)
		return (*ptr);
	res = ft_strnew(pre + i + 1);
	pre = pre - ft_strlen(&(*ptr)[i]);
	while (--pre >= 0)
		res[pre] = '0';
	res = ft_strjoin(res, &(*ptr)[i]);
	free(*ptr);
	if (i == 1)
		res = ft_strjoin("-", res);
	else if (ft_strchr(format, '+') != NULL)
		res = ft_strjoin("+", res);
	return (res);
}

char	*width_str(char **ptr, const char *restrict format)
{
	int		i;
	int		j;
	int		wid;
	char	*res;
	char	c;

	i = -1;
	while (!(format[++i] >= '0' && format[i] <= '9'))
		if (!format[i] || format[i] == '.')
			return (*ptr);
	wid = ft_atoi(&format[i]);
	c = ' ';
	if (format[0] == '0' && ft_strchr(format, '.') == NULL)
		c = '0';
	if (ft_strlen(*ptr) >= wid)
		return (*ptr);
	res = ft_strnew(wid + 1);
	i = 0;
	if (((*ptr)[0] == '-' || (*ptr)[0] == '+') && ft_strchr(format, '.') == NULL
		&& c != ' ')
		res[i++] = (*ptr)[0];
	j = i;
	wid = wid - ft_strlen(&(*ptr)[i]);
	while (i < wid)
		res[i++] = c;
	res = ft_strcat(res, &(*ptr)[j]);
	free(*ptr);
	return (res);
}
