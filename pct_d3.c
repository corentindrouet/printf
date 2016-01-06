/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:01:57 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/06 12:00:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*aj_zero(char **ptr, const char *restrict format)
{
	int		len;
	int		i;
	char	*res;

	i = -1;
	while (format[++i] != '.')
		if (!format[i])
			return (*ptr);
	i = ft_atoi(&format[++i]);
	if (i <= (int)ft_strlen(*ptr))
		return (*ptr);
	if (ft_strchr(format, '+') != NULL)
		i++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	len = i - (int)ft_strlen(*ptr);
	while (len > 0)
		res[--len] = '0';
	len = i - (int)ft_strlen(*ptr);
	ft_strcpy(&res[len], *ptr);
	free(*ptr);
	return (res);
}

void	aj_decal_d(int i, char **ptr, char *res, char c)
{
	int	j;

	j = ft_strlen(*ptr);
	j--;
	while (j >= 0)
		res[i--] = (*ptr)[j--];
	while (i >= 0)
		res[i--] = c;
}

void	aj_decal_g(int i, const char *restrict format, char *res, char **ptr)
{
	int	j;

	j = ft_strlen(*ptr);
	ft_strcpy(res, *ptr);
	if (ft_strchr(format, '+') != NULL)
		i--;
	while (j < (i + 1))
		res[j++] = ' ';
}
