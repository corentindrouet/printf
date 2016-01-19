# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 13:04:33 by cdrouet           #+#    #+#              #
#    Updated: 2016/01/19 09:30:56 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = libft/

SRC = ft_printf.c \
	  pct_d.c \
	  pct_d2.c \
	  spec_f.c \
	  pct_d3.c \
	  pct_s.c \
	  pct_gs.c \
	  pct_p.c \
	  pct_gd.c \
	  pct_i.c \
	  pct_o.c \
	  pct_o2.c \
	  pct_go.c \
	  pct_u.c \
	  pct_gu.c \
	  pct_x.c \
	  pct_gx.c \
	  pct_c.c \
	  pct_gc.c \
	  ft_atoi.c \
	  ft_ctoa_base.c \
	  ft_isdigit.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_ltoa_base.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strchr.c \
	  ft_strcpy.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strrchr.c \
	  ft_strsub.c \
	  ft_toupper.c \
	  ft_strcat.c \
	  spec_f2.c \
	  ft_strcmp.c \
	  ft_diese.c \
	  ft_atoi_base.c \
	  ft_putwchar_t.c

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

$(NAME) :
	gcc $(FLAG) -c $(SRC) ;
	ar rc $(NAME) $(BIN) ; ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(BIN)

libftclean :
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)

libftfclean : libftclean
	make -C libft/ fclean

re : fclean all
