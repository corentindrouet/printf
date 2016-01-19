/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 09:26:03 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main()
{
	int		i;
	char	*ptr = setlocale(LC_ALL, "");

//	i = 945;
//	printf("%}", 123);
//	printf("%#.1x\n", 42);
//	ft_printf(" | %d -- ft_printf\n", ft_printf("%C", L'猫'));
//	write(1, &i, 1);
//	printf(" | %d -- printf\n", printf("%C", L'猫'));
//	ft_printf("{%-15Z}", 123);
	printf("%d", ft_atoi_base(ft_itoa_base(1234, 2), 2));
	return (0);
}
