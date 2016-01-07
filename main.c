/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/07 14:29:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
//	ft_printf(" %+-hhd %d %.1d % d\n", (char)'A', 123, 456, 7);
//	printf("%lls\n", "bonjour");
	wchar_t str[10] = L"bonjour\x82";
	int	i;
	
	i = -1;
	while (str[++i] != 0)
		write(1, &str[i], sizeof(wchar_t));
	return (0);
}
