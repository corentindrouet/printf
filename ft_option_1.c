/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 08:14:56 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/21 15:41:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus(char *str, int width)
{
	int	len;

	len = ft_decal(str, width);
	if (len > 0)
		str[len - 1] = '+';
	else
	{
		len = ft_strlen(str);
		while (len > 0)
		{
			str[len] = str[len - 1];
			len--;
		}
		str[0] = '+';
	}
}

int		ft_decal(char *str, int width)
{
	int	len;

	len = ft_strlen(str);
	if (len >= width)
		return (-1);
	str[width] = '\0';
	while (len > 0)
	{
		str[width - 1] = str[len - 1];
		width--;
		len--;
	}
	len = -1;
	while (++len < width)
		str[len] = ' ';
	return (width);
}

void	ft_moin(char *str, int width)
{
	int	len;

	len = ft_strlen(str);
	if (len >= width)
		width = len;
	while (len < width)
	{
		str[len] = ' ';
		str[len + 1] = '\0';
		len++;
	}
}
