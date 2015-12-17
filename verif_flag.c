/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:18:03 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/17 14:38:48 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	verif_flag(const char * restrict f)
{
	char	c;

	c = -1;
	if (f[0] == '-' || f[0] == '+' || f[0] == ' ' || f[0] == '#' || f[0] == '0')
		c = f[0];
	return (c);
}

int		verif_width(const char * restrict f)
{
	return (ft_atoi(f));
}

int		verif_precision(const char * restrict f)
{
	return (ft_atoi(f));
}

char	verif_lenght(const char * restrict f)
{
	if (f[0] == 'h' || (f[0] == 'h' && f[1] == 'h')
		|| f[0] == 'l' || (f[0] == 'l' && f[1] == 'l')
			|| f[0] == 'j' || f[0] == 'z')
		return (f[0]);
	return (-1);
}

char	verif_spec(const char * restrict f)
{
	char	*str;
	int		i;

	str = "sSpdDioOuUxXcC";
	i = -1;
	while (str[++i])
		if (f[0] == str[i])
			return (f[0]);
	return (-1);
}
