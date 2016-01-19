/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:49:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 09:34:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_2o(char *str)
{
	char	*mask[2];
	int		i;

	mask[0] = ft_strjoin("11", "0");
	mask[1] = ft_strjoin("10", &str[ft_strlen(str) - 7]);
	i = -1;
	while ((ft_strlen(mask[0]) + ft_strlen(ft_strsub(str, 0, ft_strlen(str) - 7))) < 8)
		mask[0] = ft_strjoin(mask[0], "x");
	mask[0] = ft_strjoin(mask[0], ft_strsub(str, 0, ft_strlen(str) - 7));
	while (mask[0][++i])
		if (mask[0][i] == 'x')
			mask[0][i] = '0';
	i = ft_atoi_base(mask[0], 2);
	write(1, &i, 1);
	i = ft_atoi_base(mask[1], 2);
	write(1, &i, 1);
	return (2);
}

int			ft_putwchar_t(wchar_t s)
{
	unsigned int	wc;
	char			*str;

	wc = s;
	str = ft_uitoa_base(wc, 2);
	if (ft_strlen(str) <= 7)
	{
		write(1, &s, 1);
		return (1);
	}
	else if (ft_strlen(str) <= 11)
		return (put_2o(str));
	return (0);
}
