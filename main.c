/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:06:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 10:31:29 by cdrouet          ###   ########.fr       */
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
	char	spec[20] = "sSpdDioOuUxXcC%";
	char	str[30] = "%+-0.0s";
	int		width;
	int		precis;
	int		i;

	i = -1;
	while (++i < 15)
	{
		width = -1;
		while (++width <= 9)
		{
			precis = -1;
			while (++precis <= 9)
			{
				str[6] = spec[i];
				str[3] = width + '0';
				str[5] = precis + '0';
				if (spec[i] == 's' || spec[i] == 'S')
				{
					ft_printf("| %d | %s\n", ft_printf(str, NULL), str);
//					printf("| %d | %s\n", printf(str, NULL), str);
				}
				else
				{
					ft_printf("| %d | %s\n", ft_printf(str, 0), str);
//					printf("| %d | %s\n", printf(str, 0), str);
				}
			}
		}
	}
}
