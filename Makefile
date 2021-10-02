# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwhwang@student.42.fr <jiwhwang>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 17:46:26 by jiwhwang          #+#    #+#              #
#    Updated: 2021/06/21 00:30:54 by jiwhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

HEADER = ft_printf.h

	
OBJS = 	ft_printf.o\
		ft_printf_utils_1.o\
		ft_printf_utils_2.o\
		ft_printf_utils_3.o\
		ft_printf_utils_4.o\
		ft_printf_utils_5.o\
		ft_printf_utils_6.o\
		ft_printf_utils_7.o\
		ft_printf_utils_8.o\
		ft_printf_utils_9.o\
		ft_printf_utils_10.o\
	
AR = ar -rc

all : $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all
