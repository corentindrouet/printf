/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/12 14:32:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

typedef union	u_test
{
	wchar_t	*i;
	char	*c;
	int		j;
}				t_test;

int		main()
{
	t_test	p;
	p.i = L"è";
//	printf("%s", "正体字 / 正體字è");
	ft_printf("%30x\n", 'o');
	write(1, p.i, 8);
//	ft_putnbr(sizeof(p));
	return (0);
}
