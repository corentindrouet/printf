/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 11:43:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main()
{
	wchar_t *p = NULL;
	char	*ptr = setlocale(LC_ALL, "");

	ft_printf(" | %d -- ft_printf\n", ft_printf("%S prout %S", L"我是一只猫。", p));
	printf(" | %d -- printf\n", printf("%S prout %S", L"我是一只猫。", p));
	return (0);
}
