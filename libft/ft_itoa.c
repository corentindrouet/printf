/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:13:09 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/01 09:20:54 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoaneg(int i, char *ptr)
{
	while (--i > 0)
		ptr[i] = ptr[i - 1];
	ptr[0] = '-';
}

static void	ft_reverse(char *ptr)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(ptr);
	while (++i < (len / 2))
	{
		ptr[i] = ptr[i] + ptr[len - i - 1];
		ptr[len - i - 1] = ptr[i] - ptr[len - i - 1];
		ptr[i] = ptr[i] - ptr[len - i - 1];
	}
	ptr[len] = '\0';
}

static int	ft_cpyritoa(char *ptr, unsigned int cp)
{
	int	i;

	i = 0;
	while (cp > 0)
	{
		ptr[i++] = (cp % 10) + '0';
		cp /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*ptr;
	int				i;
	int				neg;
	unsigned int	cp;

	cp = (unsigned int)n;
	neg = 0;
	if (n < 0)
	{
		cp = -n;
		neg++;
	}
	i = 0;
	ptr = (char*)malloc(sizeof(char) * 12);
	if (ptr)
	{
		if (cp == 0)
			ptr[i++] = '0';
		i += ft_cpyritoa(ptr, cp);
		ptr[i] = '\0';
		ft_reverse(ptr);
		if (neg > 0)
			ft_itoaneg(ft_strlen(ptr) + 1, ptr);
	}
	return (ptr);
}
