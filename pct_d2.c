/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/04 10:28:54 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pct_jd(va_list ap)
{
	intmax_t	i;

	i = va_arg(ap, intmax_t);
}

void	pct_zd(va_list ap)
{
	signed size_t	i;

	i = va_arg(ap, signed size_t);
}

void	pct_dd(va_list ap)
{
	int		i;

	i = va_arg(ap, int);
}
