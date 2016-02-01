/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 11:57:02 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

char	*precis_str(char **ptr, const char *restrict format);
char	*width_str(char **ptr, const char *restrict format);

int		main()
{
	char	*ptr = setlocale(LC_ALL, "");
	char	str[50] = "%#.0x, %S --|%-7d, %p";
	int		i;

	ft_printf("|--| retour : %d\n", ft_printf(str, 1234, L"Blabla", 1234, &i));
	printf("|--| retour : %d\n", printf(str, 1234, L"Blabla", 1234, &i));
//	ft_printf(" | %d -- ft_printf\n", ft_printf("%d-%zn-%zd", 10, &n, n));
//	printf(" | %d -- printf\n", printf("%d-%zn-%zd", 10, &m, m));
	return (0);
}
