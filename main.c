/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/18 09:16:01 by cdrouet          ###   ########.fr       */
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
//	printf("%}", 123);
//	printf("%#.1x\n", 42);
	ft_printf(" | %d -- ft_printf\n", ft_printf("%#.o, %#.0o", 0, 0));
	printf(" | %d -- printf\n", printf("%#.o, %#.0o", 0, 0));
//	ft_printf("{%-15Z}", 123);
	return (0);
}
