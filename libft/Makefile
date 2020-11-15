
NAME=libft.a

HEADER=libft.h

CC=gcc

CFLAGS=-Wall -Wextra -Werror -I.

RM=rm -f

SRC =ft_memchr.c ft_isalpha.c ft_putchar_fd.c ft_strchr.c\
	ft_strlen.c ft_strtrim.c ft_atoi.c ft_isascii.c\
	ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c\
	ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c\
	ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c ft_memmove.c\
	ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c\
	ft_isalnum.c ft_itoa.c ft_memccpy.c ft_memset.c ft_split.c\
	ft_strlcpy.c ft_strrchr.c

OBJ =		$(SRC:.c=.o)

BONUS =		ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c\
		ft_lstmap.c ft_lstclear.c ft_lstnew.c\
		ft_lstdelone.c ft_lstsize.c ft_lstiter.c

BONUS_OBJ =	$(BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ) $(HEADER)

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

bonus:	$(OBJ) $(BONUS_OBJ)
		ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)