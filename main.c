/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 15:08:00 by cdrouet          ###   ########.fr       */
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
	//printf(" | %d\n", printf("%4.15d", -424242));
	printf("% d\n", 9999);
//	ft_printf(" | %d\n", ft_printf("%4.15d", -424242));
	ft_printf("% d\n", 9999);
	return (0);
}
