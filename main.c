/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:06:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/02 09:04:48 by cdrouet          ###   ########.fr       */
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
	char	str[250] = "% 5d, %c, % +07.8d, % o, % 0hd, % ji, %#-7.2o, %%%%, %-+5.5d, % 9.3s, %#8.1X, %C";

	ft_printf("| %d ft_printf\n", ft_printf(str, 123, 'y', 123, 123, 123, 123, 123, 123, "bonjour", 123, L'繁'));
	printf("| %d printf\n", printf(str, 123, 'y', 123, 123, 123, 123, 123, 123, "bonjour", 123, L'繁'));
}
