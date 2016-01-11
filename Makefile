# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 13:04:33 by cdrouet           #+#    #+#              #
#    Updated: 2016/01/11 09:49:22 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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

BIN = ft_printf.o \
	  pct_d.o \
	  pct_d2.o \
	  spec_f.o \
	  pct_d3.o \
	  pct_s.o \
	  pct_gs.o \
	  pct_p.o \
	  pct_gd.o \
	  pct_i.o \
	  pct_o.o \
	  pct_o2.o \
	  pct_go.o \
	  pct_u.o \
	  pct_gu.o \
	  pct_x.o \
	  pct_gx.o \
	  pct_c.o \
	  pct_gc.o \

FLAG = -Wall -Wextra -Werror

$(NAME) :
	make -C libft/ ;
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
