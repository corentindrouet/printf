/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainperso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:22:15 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 11:55:27 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#include "ft_printf.h"

int	main()
{
	setlocale(LC_ALL, "");

	ft_printf("| %d |\n", ft_printf("%+-3.1d", 0));
	printf("| %d |\n", printf("%+-3.1d", 0));
}
