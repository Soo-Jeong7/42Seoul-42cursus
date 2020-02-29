# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 16:43:53 by jko               #+#    #+#              #
#    Updated: 2020/02/29 17:12:10 by jko              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = memset \
	bzero \
	memcpy \
	memccpy \
	memmove \
	memchr \
	memcmp \
	strlen \
	strlcpy \
	strlcat \
	strchr \
	strrchr \
	strnstr \
	strncmp \
	atoi \
	isalpha \
	isdigit \
	isalnum \
	isascii \
	isprint \
	toupper \
	tolower \
	calloc \
	strdup \
	substr \
	strjoin \
	strtrim \
	split \
	itoa \
	strmapi \
	putchar_fd \
	putstr_fd \
	putendl_fd \
	putnbr_fd


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

NAME = libft.a

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rcs $@ $^ 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
