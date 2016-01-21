/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/21 13:30:13 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

char	*precis_str(char **ptr, const char *restrict format);

int		main()
{
	char	*ptr = setlocale(LC_ALL, "");
	char	*str;

	str = ft_itoa(-1234);
	str = precis_str(&str, "%.7d");
	printf("|%15.7d|\n|%s|", -1234, str);
//	ft_printf(" | %d -- ft_printf\n", ft_printf("%4.1S", L"Jambon"));
//	printf(" | %d -- printf\n", printf("%+.10d", 123456789));
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
