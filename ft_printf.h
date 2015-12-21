/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:36:36 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/21 12:53:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char * restrict format, ...);
void	pct_d(va_list ap, char *c, int *d);
char	verif_flag(const char * restrict f);
int		verif_width(const char * restrict f);
int		verif_precision(const char * restrict f);
char	verif_lenght(const char * restrict f);
char	verif_spec(const char * restrict f);
void	ft_plus(char *str, int width);
int		ft_decal(char *str, int width);
void	ft_moin(char *str, int width);

#endif
