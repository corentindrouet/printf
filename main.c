/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/27 11:56:24 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

char	*precis_str(char **ptr, const char *restrict format);
char	*width_str(char **ptr, const char *restrict format);
/*
char	*ft_dtoa(double i)
{

}
*/
int		main()
{
	char	*ptr = setlocale(LC_ALL, "");
	char	str[40] = "{{cyan}%3s{eoc}, {rose}prout{eoc}, %-5d}";
	char	lol[10] = "{cyan}";
	int		i;

//	ft_printf(" | %d -- ft_printf\n", ft_printf(str, "bonjour"));
//	a = (a >> 1) << 1;
//	ft_printf(" | %d -- ft_printf\n", ft_printf("", 42));
	printf(" | %d -- printf\n", printf("\033[32m\033[7mbonjour\033[0m"));
	return (0);
}
