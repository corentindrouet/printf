/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:06:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/02 13:52:58 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#include "ft_printf.h"

int	main()
{
	setlocale(LC_ALL, "");
	char	str[300] = "% 5d, %c, % +07.8d, % o, {% 0hd{, % ji,} %#-7.2o}, %%%%, %-+5.5d, % 9.3s, %#8.1X, %C, %-+05.5S, |rycgeuq|{prout} %-08% %-+3.6hhd = | %+9.4U %+-p... % #-.3o[{;;';!@#$%^&*()_+}] % 0.5d 4839 ]] %9.3s )) %+13d pp %8.4hho, %-8hd||||% -7.3lld";

	ft_printf("| %d ft_printf\n", ft_printf(str, 123, 'y', 123, 123, 123, 123, 123, 123, "bonjour", 123, L'繁', L"繁体字", (char)'P', 123, str, 123, 123, "%dbonjour", 5i, 't', (short)12, 123456789123456));
	printf("| %d printf\n", printf(str, 123, 'y', 123, 123, 123, 123, 123, 123, "bonjour", 123, L'繁', L"繁体字", (char)'P', 123, str, 123, 123, "%dbonjour", 5, 't', (short)12, 123456789123456));
}
