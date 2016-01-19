/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:47:00 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 14:12:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_bytes_wchar(wchar_t s)
{
	unsigned int	wc;
	char			*str;

	wc = s;
	str = ft_uitoa_base(wc, 2);
	if (ft_strlen(str) <= 7)
		return (1);
	else if (ft_strlen(str) <= 11)
		return (2);
	else if (ft_strlen(str) <= 16)
		return (3);
	else
		return (4);
}

int		nbr_bytes_wstr(wchar_t *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] != 0)
		res += nbr_bytes_wchar(str[i++]);
	return (res);
}

wchar_t	*decal_wstr(wchar_t **str, const char *restrict format)
{
	wchar_t	*ptr;
	int		i;
	char	c;
	int		decal;

	i = -1;
	while (format[++i])
		if (format[i] >= '0' && format[i] <= '9')
			break;
		else if (format[i] == '.')
			return (*str);
	c = ' ';
	if (format[i] == '0')
		c = '0';
	decal = ft_atoi(&format[i]);
	if (decal <= nbr_bytes_wstr(*str))
		return (*str);
	ptr = (wchar_t*)malloc(decal + 1);
	if (ft_strchr(format, '-') == NULL)
	{
		decal = decal - nbr_bytes_wstr(*str);
		while (--decal >= 0)
			ptr[decal] = c;
		return (ft_wstrcat(ptr, *str));
	}
	else
	{
		ptr[0] = 0;
		ft_wstrcat(ptr, *str);
		decal = nbr_bytes_wstr
	}
}

wchar_t	*ft_wstrcat(wchar_t *dest, wchar_t *src)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (dest[j] != 0)
		j++;
	while (src[++i] != 0)
		dest[j + i] = src[i];
	dest[j + i] = 0;
	return (dest);
}
