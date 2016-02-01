/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_essai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:03:20 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 13:38:53 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_signed(char **ptr)
{
	char	*res;

	if ((*ptr) == NULL)
		return (*ptr)
	res = ft_strjoin("+", (*ptr));
	free(*ptr);
	return (res);
}

char	*ft_precis(char **ptr, const char *restrict format)
{
	char	*res;
	int		decal;

	decal = ft_atoi(ft_strchr(format, '.') + 1);
	if ()
	if (decal <= ft_strlen(*ptr))
}
