# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktyu <ktyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 16:47:17 by ktyu              #+#    #+#              #
#    Updated: 2026/09/09 20:15:09 by ktyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs

FT_FILE := ft_append_char.c ft_isalnum.c ft_itoa.c \
			ft_strdup.c ft_strjoin_free.c ft_strlen.c \
			ft_strncmp.c ft_strndup.c ft_memcpy.c \
			ft_strndup.c ft_strcmp.c

OBJS := $(FT_FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

.PHONY: all clean fclean re bonus