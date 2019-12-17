# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eherrero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 13:05:48 by eherrero          #+#    #+#              #
#    Updated: 2019/12/16 16:40:14 by eherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

EXTRA=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -O3

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRC2=ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	 ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
	 ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c

SRC=ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strndup.c \
		 ft_split.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		 ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		 ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		 ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_atoi.c ft_isalnum.c ft_bzero.c ft_calloc.c ft_arraynjoin.c\
		 ft_in_set.c ft_dgts.c ft_dgts_base.c ft_itoa_base.c ft_itoa_unsigned.c \
		 str_treatment.c print_options.c ft_printf.c ft_printnchr.c \

OBJ=$(SRC:.c=.o)

OBJ2=$(SRC2:.c=.o) 

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(EXTRA):

all: $(NAME)

bonus: 
	$(CC) $(CFLAGS) -c $(SRC) $(SRC2) $(DHDIRS)
	ar rc $(EXTRA) $(OBJ2) $(OBJ)
	ranlib $(EXTRA)

clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all bonus
