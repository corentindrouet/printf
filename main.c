/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 11:23:29 by cdrouet          ###   ########.fr       */
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
	wchar_t *p = NULL;
	char	*ptr = setlocale(LC_ALL, "");

	i = 945;
//	ft_printf(" | %d -- ft_printf\n", ft_printf("%C", L'猫'));
//	printf("%d", ft_atoi_base(ft_itoa_base(1234, 2), 2));
	ft_printf(" | %d -- ft_printf\n", ft_printf("%ls", p));
	printf(" | %d -- printf\n", printf("%ls", p));
	return (0);
}
