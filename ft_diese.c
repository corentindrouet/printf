/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:59:37 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/28 11:09:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_diese_o(char **ptr)
{
	char	*res;
	int		i;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if ((*ptr)[i] == '0')
		return (*ptr);
	else if (i > 0)
	{
		(*ptr)[i - 1] = '0';
		return (*ptr);
	}
	else if (i == 0)
	{
		res = ft_strnew(1);
		res = ft_strjoin("0", *ptr);
		return (res);
	}
	return (*ptr);
}

static char	*ft_diese_gx(const char *restrict format, char **ptr)
{
	int		i;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if ((*ptr)[i] == '0' && (*ptr)[i + 1] == '0' && !ft_strchr(format, '.'))
	{
		(*ptr)[i + 1] = 'X';
		return (*ptr);
	}
	else if (ft_strchr(format, '.') != NULL)
		return (ft_strjoin(ft_strjoin(ft_strsub(*ptr, 0, i), "0X"),
			ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i)));
	else if (i > 1)
	{
		(*ptr)[i - 2] = '0';
		(*ptr)[i - 1] = 'X';
	}
	else if (i <= 1)
		return (ft_strjoin("0X", ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i)));
	return (*ptr);
}

static char	*ft_diese_x(const char *restrict format, char **ptr)
{
	int		i;
	int		dec;
	int		j;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if ((*ptr)[i] == '0' && (*ptr)[i + 1] == '0' && !ft_strchr(format, '.'))
	{
		(*ptr)[i + 1] = 'x';
		return (*ptr);
	}
	else if (ft_strchr(format, '.') != NULL && i >= 2)
		return (ft_strjoin(ft_strjoin(ft_strsub(*ptr, 0, i - 2), "0x"),
			ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i)));
	else if (ft_strchr(format, '.') != NULL && i < 2)
		return (ft_strjoin(ft_strjoin(ft_strsub(*ptr, 0, i), "0x"),
			ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i)));
	else if (i > 1)
	{
		(*ptr)[i - 2] = '0';
		(*ptr)[i - 1] = 'x';
	}
	else if (i <= 1)
	{
		if ((*ptr)[i] == '0' && ft_strchr(format, 'p') == NULL)
			i++;
		dec = 0;
		j = ft_strlen(*ptr);
		while ((*ptr)[--j] == ' ' && dec <= 2
			&& j > (int)(ft_strlen(*ptr) - 3))
			dec++;
		return (ft_strjoin("0x", ft_strsub(*ptr, i, (int)ft_strlen(*ptr) - i - dec)));
	}
	return (*ptr);
}

char		*ft_diese(const char *restrict format, char **ptr, int base, int m)
{
	char	*res;

	res = *ptr;
	if (ft_atoi(*ptr) == 0 && ft_strchr(format, 'p') == NULL)
		return (*ptr);
	if (base == 8)
		res = ft_diese_o(ptr);
	else if (base == 16 && m == 0)
		res = ft_diese_x(format, ptr);
	else if (base == 16 && m == 1)
		res = ft_diese_gx(format, ptr);
	return (res);
}
