/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/21 11:29:13 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main()
{
	char	*ptr = setlocale(LC_ALL, "");

	ft_printf(" | %d -- ft_printf\n", ft_printf("%15.4S", L"我是一只猫。"));
	printf(" | %d -- printf\n", printf("%15.4S", L"我是一只猫。"));
//	printf(" | %d -- printf\n", printf("%.4S", L"我是一只猫。"));
/*	printf(" | %d -- printf\n", printf("4567 |%-10]5d| plip", 12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("4567 |%-10]5d| plip", 12));
	printf(" | %d -- printf\n", printf("4567 |%10]5d| plip", 12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("4567 |%10]5d| plip", 12));
	printf(" | %d -- printf\n", printf("|%10.5d|", -12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("|%10.5d|", -12));
	printf(" | %d -- printf\n", printf("|%10d|", -12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("|%10d|", -12));
	printf(" | %d -- printf\n", printf("|%010d|", -12)); 
	ft_printf(" | %d -- ft_printf\n", ft_printf("|%010d|", -12));
	printf(" | %d -- printf\n", printf("|%-10.5d|", -12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("|%-10.5d|", -12));
	printf(" | %d -- printf\n", printf("|%-010.5d|", -12));
	ft_printf(" | %d -- ft_printf\n", ft_printf("|%-010.5d|", -12));*/
	return (0);
}
