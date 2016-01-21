/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_essai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:03:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/21 13:28:58 by cdrouet          ###   ########.fr       */
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
	return (res);
}

//char	*width_str(char **ptr)
