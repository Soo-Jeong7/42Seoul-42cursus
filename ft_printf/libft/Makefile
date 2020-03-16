# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 16:43:53 by jko               #+#    #+#              #
#    Updated: 2020/03/16 20:56:11 by jko              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

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
	strchrset \
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
	strndup \
	substr \
	strjoin \
	strtrim \
	split \
	itoa \
	lltoa_base \
	ulltoa_base \
	strmapi \
	putchar_fd \
	putstr_fd \
	putendl_fd \
	putnbr_fd

FILES_B = lstnew \
	  lstadd_front \
	  lstsize \
	  lstlast \
	  lstadd_back \
	  lstdelone \
	  lstclear \
	  lstiter \
	  lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rcs $@ $^ 

bonus: $(OBJS_B)
	ar rcs $(NAME) $^

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
