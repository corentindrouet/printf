/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 15:49:29 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main()
{
//	int	i;

//	printf("%o\n", 2147483647);
//	ft_printf("%o\n", -99);
//	ft_putstr(ft_itoa_base(2147483647, 8));
	printf("uint : %d\nuchar : %d\nushort : %d\nulong : %d\nulong long : %d\nuintmax_t : %d\nsize_t : %d\n", (int)sizeof(unsigned int), (int)sizeof(unsigned char), (int)sizeof(unsigned short), (int)sizeof(unsigned long), (int)sizeof(unsigned long long), (int)sizeof(uintmax_t), (int)sizeof(size_t));
	return (0);
}
