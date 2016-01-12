/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:36:45 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 10:29:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	if (c == 0)
		return ((char*)&s[ft_strlen(s)]);
	else
	{
		i = -1;
		while (s[++i] != '\0')
		{
			if (s[i] == c)
				str = (char*)&s[i];
		}
	}
	return (str);
}
