/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:47:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 11:14:05 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		i = -n;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}

void	ft_putnbr_base(unsigned long n, int base)
{
	char	*str;

	str = "0123456789abcdef";
	if (n >= (unsigned long)base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
	{
		ft_putchar(str[n]);
	}
}
