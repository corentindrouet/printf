/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/14 13:56:53 by cdrouet          ###   ########.fr       */
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
	printf(" | %d\n", printf("%"));
//	printf("%}", 123);
//	printf("%#.1x\n", 42);
	ft_printf(" | %d\n", ft_printf("%"));
//	ft_printf("{%-15Z}", 123);
	return (0);
}
