/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 12:03:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main()
{
	int	i;
	char	*str;
//	void	*ptr;

	i = 0;
//	ft_printf("%-10i\n", 123);
	printf("%p\n", &i);
//	ptr = &i;
//	ft_putnbr_base(123, 16);
	str = ft_itoa_base((long)&i, 16);
	ft_putstr(str);
	return (0);
}
