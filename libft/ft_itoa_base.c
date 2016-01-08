/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:32:03 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 11:49:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recur_itoa_b(unsigned long nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned long)base)	
	{
		index = recur_itoa_b(nb / base, base, ptr, index);
		index = recur_itoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_itoa_base(long nb, int base)
{
	unsigned long	i;
	char			*ptr;
	int				index;

	i = nb;
	ptr = ft_strnew(20);
	index = 0;
	if (nb < 0)
	{
		ptr[index++] = '-';
		i = -nb;
	}
	recur_itoa_b(i, base, ptr, index);
	return (ptr);
}
