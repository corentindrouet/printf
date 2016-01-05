/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:36 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/05 11:38:25 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		cont_carac(char *s, char c);
char	*aj_plus(char **ptr);
char	*ft_lltoa(long long nbr);
int		recur_lltoa(unsigned long long nbr, char *ptr, int index);
int		ft_printf(const char *restrict format, ...);
void	pct_d(va_list ap, const char *restrict format);
char	verif_flag(const char *restrict f);
int		verif_width(const char *restrict f);
int		verif_precision(const char *restrict f);
char	verif_lenght(const char *restrict f);
char	verif_spec(const char *restrict f);
void	ft_plus(char *str, int width);
int		ft_decal(char *str, int width);
void	ft_moin(char *str, int width);
void	pct_hhd(va_list ap, const char *restrict format);
void	pct_hd(va_list ap, const char *restrict format);
void	pct_lld(va_list ap, const char *restrict format);
void	pct_ld(va_list ap, const char *restrict format);
void	pct_zd(va_list ap, const char *restrict format);
void	pct_jd(va_list ap, const char *restrict format);
void	pct_dd(va_list ap, const char *restrict format);

#endif
