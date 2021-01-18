# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeribal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 19:31:42 by lmeribal          #+#    #+#              #
#    Updated: 2021/01/18 17:37:49 by lmeribal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

HEADER=includes/ft_printf.h

CC=gcc

CFLAGS=-Wall -Wextra -Werror -I includes

RM=rm -f

SRC =libft/ft_putchar_fd.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_atoi.c libft/ft_isdigit.c\
	libft/ft_strdup.c libft/ft_substr.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c\
	libft/ft_itoa.c libft/ft_strlcpy.c libft/ft_itoa_base.c libft/ft_isalpha.c libft/ft_toupper.c\
	libft/ft_strjoin.c libft/ft_strncmp.c\
	ft_printf.c main.c \
	parsers/struct_parser.c \
	processors/s_processor.c processors/c_processor.c processors/di_processor.c\
	processors/u_processor.c processors/xX_processor.c processors/p_processor.c\
	processors/values_processor.c

OBJ =		$(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ) $(HEADER)
			#gcc $(CFLAGS) $(SRC)

%.o: %.c $(HEADER) @$(CC) -c $< -o $@

.PHONY: clean

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

.PHONY: fclean

fclean: clean
	$(RM) $(NAME)

.PHONY: re

re: fclean all

.PHONY: bonus
