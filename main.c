/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:58:50 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 09:40:50 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

char	*precis_str(char **ptr, const char *restrict format);
char	*width_str(char **ptr, const char *restrict format);
/*
char	*ft_dtoa(double i)
{

}
*/
int		main()
{
	char	*ptr = setlocale(LC_ALL, "");
	ssize_t	n;
	ssize_t	m;

	ft_printf(" | %d -- ft_printf\n", ft_printf("%d-%zn-%zd", 10, &n, n));
	printf(" | %d -- printf\n", printf("%d-%zn-%zd", 10, &m, m));
	return (0);
}
