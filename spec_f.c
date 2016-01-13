/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:35:24 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 09:32:01 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_lltoa(long long nbr)
{
	char				*ptr;
	unsigned long long	i;
	int					index;

	ptr = ft_strnew(30);
	index = 0;
	i = nbr;
	if (nbr < 0)
	{
		i = -nbr;
		index++;
		ptr[0] = '-';
	}
	index = recur_lltoa(i, ptr, index);
	ptr[index] = '\0';
	return (ptr);
}

int			recur_lltoa(unsigned long long nbr, char *ptr, int index)
{
	if (nbr >= 10)
	{
		index = recur_lltoa(nbr / 10, ptr, index);
		index = recur_lltoa(nbr % 10, ptr, index);
		return (index);
	}
	else
	{
		ptr[index] = nbr + '0';
		return (index + 1);
	}
	return (index);
}

static int	recur_uitoa_b(unsigned int nbr, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr >= (unsigned int)base)
	{
		index = recur_uitoa_b(nbr / base, base, ptr, index);
		index = recur_uitoa_b(nbr % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nbr];
		index++;
	}
	return (index);
}

char		*ft_uitoa_base(unsigned int nbr, int base)
{
	char	*ptr;

	ptr = ft_strnew(20);
	recur_uitoa_b(nbr, base, ptr, 0);
	return (ptr);
}
