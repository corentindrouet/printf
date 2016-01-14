/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/14 11:07:00 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main()
{
	int		i;

	i = 5;
	//printf(" | %d\n", printf("%4.15d", -424242));
	printf("%.1x\n", 42);
	printf("%#.1x\n", 42);
//	ft_printf(" | %d\n", ft_printf("%4.15d", -424242));
	ft_printf("%#.1x", 42);
	return (0);
}
