/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:36 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/07 11:14:36 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

void	aj_decal_g(int i, const char *restrict format, char *res, char **ptr);
void	aj_decal_d(int i, char **ptr, char *res, char c);
char	*aj_zero(char **ptr, const char *restrict format);
char	*aj_decal(char **ptr, const char *restrict format);
int		cont_carac(char *s, char c);
char	*aj_plus(char **ptr);
char	*ft_lltoa(long long nbr);
int		recur_lltoa(unsigned long long nbr, char *ptr, int index);
int		ft_printf(const char *restrict format, ...);
void	pct_d(const char *restrict format, va_list ap);
void	pct_s(const char *restrict format, va_list ap);
void	pct_gs(const char *restrict format, va_list ap);
void	pct_p(const char *restrict format, va_list ap);
void	pct_gd(const char *restrict format, va_list ap);
void	pct_i(const char *restrict format, va_list ap);
void	pct_o(const char *restrict format, va_list ap);
void	pct_go(const char *restrict format, va_list ap);
void	pct_u(const char *restrict format, va_list ap);
void	pct_gu(const char *restrict format, va_list ap);
void	pct_x(const char *restrict format, va_list ap);
void	pct_gx(const char *restrict format, va_list ap);
void	pct_c(const char *restrict format, va_list ap);
void	pct_gc(const char *restrict format, va_list ap);
void	pct_pct(const char *restrict format, va_list ap);
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
