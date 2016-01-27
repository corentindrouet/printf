/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/27 10:40:55 by cdrouet          ###   ########.fr       */
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
	ft_printf("{vert} | %d -- ft_printf{eoc}\n", ft_printf(str, "bonjour", 123));
	return (0);
}
