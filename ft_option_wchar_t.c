/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:47:00 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 11:57:33 by cdrouet          ###   ########.fr       */
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

int		decal_wstr(wchar_t *str, const char *restrict format)
{
	(void)str;
	(void)format;
	return (0);
}
