/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/07 13:46:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pct_ss(const char *restrict format, va_list ap)
{
/*	char	*ptr;
	int		i;

	ptr = (char*)va_arg(ap, char*);
	if (ft_strchr(format, '.') != NULL)
	{

	}*/
	(void)format;
	(void)ap;
}

static void	pct_ls(const char *restrict format, va_list ap)
{
	(void)format;
	(void)ap;
}

void		pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		pct_ls(format, ap);
	else
		pct_ss(format, ap);
}
