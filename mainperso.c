/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainperso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:22:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 15:33:47 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#include "ft_printf.h"
#include <limits.h>

int	main()
{
	setlocale(LC_ALL, "");

	ft_printf("| %d | ft_printf\n", ft_printf("%#zo", 0));
	printf("| %d | printf\n", printf("%#zo", 0));
}
