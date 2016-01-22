/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_wchar_t2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 09:57:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/22 14:33:11 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*precis_wchar_t(wchar_t *ptr, const char *restrict format, int nb)
{
	int		i;
	int		j;
	int		prec;
	char	*pre;
	wchar_t	*res;

	if ((pre = ft_strchr(format, '.')) == NULL)
		return (ptr);
	pre++;
	if (pre[0] == '*')
		prec = nb;
	else
		prec = ft_atoi(pre);
	if (nbr_bytes_wstr(ptr) <= prec)
		return (ptr);
	i = 0;
	j = 0;
	while ((i += nbr_bytes_wchar(ptr[j])) <= prec)
		j++;
	res = (wchar_t*)malloc(sizeof(wchar_t) * (j + 2));
		j--;
	i = j;
	while (j >= 0)
	{
		res[j] = ptr[j];
		j--;
	}
	res[i + 1] = 0;
	return (res);
}
