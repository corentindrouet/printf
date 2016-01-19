/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:36 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/19 14:12:42 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

wchar_t	*decal_wstr(wchar_t **str, const char *restrict format);
wchar_t	*ft_wstrcat(wchar_t *dest, wchar_t *src);
int		nbr_bytes_wchar(wchar_t s);
int		nbr_bytes_wstr(wchar_t *str);
int		ft_putwstr_t(wchar_t *str);
int		pct_ls(const char *restrict format, va_list ap);
int		ft_putwchar_t(wchar_t s);
int		ft_atoi_base(const char *str, int base);
int		pct_lc(const char *restrict format, va_list ap);
char	*ft_diese(const char *restrict format, char **ptr, int base, int maj);
void	ft_strtoupper(char *str);
int		pct_hho(va_list ap, const char *restrict format, int base, int maj);
int		pct_ho(va_list ap, const char *restrict format, int base, int maj);
int		pct_llo(va_list ap, const char *restrict format, int base, int maj);
int		pct_lo(va_list ap, const char *restrict format, int base, int maj);
int		pct_jo(va_list ap, const char *restrict format, int base, int maj);
int		pct_zo(va_list ap, const char *restrict format, int base, int maj);
int		pct_oo(va_list ap, const char *restrict format, int base, int maj);
void	aj_decal_g(int i, const char *restrict format, char *res, char **ptr);
void	aj_decal_d(int i, char **ptr, char *res, char c);
char	*aj_zero(char **ptr, const char *restrict format);
char	*aj_decal(char **ptr, const char *restrict format);
int		cont_carac(char *s, char c);
char	*aj_plus(char **ptr);
char	*ft_lltoa(long long nbr);
char	*ft_uitoa_base(unsigned int nbr, int base);
char	*ft_ultoa_base(unsigned long nbr, int base);
char	*ft_ulltoa_base(unsigned long long nbr, int base);
int		recur_lltoa(unsigned long long nbr, char *ptr, int index);
int		ft_printf(const char *restrict format, ...);
int		pct_d(const char *restrict format, va_list ap);
int		pct_s(const char *restrict format, va_list ap);
int		pct_gs(const char *restrict format, va_list ap);
int		pct_p(const char *restrict format, va_list ap);
int		pct_gd(const char *restrict format, va_list ap);
int		pct_i(const char *restrict format, va_list ap);
int		pct_o(const char *restrict format, va_list ap);
int		pct_go(const char *restrict format, va_list ap);
int		pct_u(const char *restrict format, va_list ap);
int		pct_gu(const char *restrict format, va_list ap);
int		pct_x(const char *restrict format, va_list ap);
int		pct_gx(const char *restrict format, va_list ap);
int		pct_c(const char *restrict format, va_list ap);
int		pct_gc(const char *restrict format, va_list ap);
int		pct_pct(const char *restrict format, va_list ap);
int		ft_plus(char *str, int width);
int		ft_decal(char *str, int width);
int		ft_moin(char *str, int width);
int		pct_hhd(va_list ap, const char *restrict format);
int		pct_hd(va_list ap, const char *restrict format);
int		pct_lld(va_list ap, const char *restrict format);
int		pct_ld(va_list ap, const char *restrict format);
int		pct_zd(va_list ap, const char *restrict format);
int		pct_jd(va_list ap, const char *restrict format);
int		pct_dd(va_list ap, const char *restrict format);

#endif
