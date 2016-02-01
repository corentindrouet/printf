/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 14:45:06 by cdrouet          ###   ########.fr       */
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
	char	str[50] = "%+06d";

	ft_printf(" | %d -- ft_printf\n", ft_printf(str, 1234));
	printf(" | %d -- printf\n", printf(str, 1234));
	return (0);
}
