# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 13:04:33 by cdrouet           #+#    #+#              #
#    Updated: 2016/01/04 14:16:39 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  pct_d.c \
	  pct_d2.c \
	  spec_f.c

BIN = ft_printf.o \
	  pct_d.o \
	  pct_d2.o \
	  spec_f.o

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
