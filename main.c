/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/08 08:02:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int		main()
{
//	ft_printf(" %d\n", (char)'A', 123, 456, 7);
	ft_printf("%-10.5s\n", "bonjour");
	printf("%-10.5s\n", "bonjour");
	return (0);
}
