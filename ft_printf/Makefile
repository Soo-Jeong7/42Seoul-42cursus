# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 16:52:44 by jko               #+#    #+#              #
#    Updated: 2020/08/24 00:11:49 by jko              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft
LIB_FLAGS = -L./libft -lft -L. -lftprintf

RM = rm -f

FILES = ft_printf \
	ft_printf_tag_parser \
	ft_printf_tag_option_parser \
	ft_printf_print_str \
	ft_printf_print_char \
	ft_printf_print_unsigned_num \
	ft_printf_print_signed_num \
	ft_printf_count \
	ft_printf_flags

SRC_DIR = ./srcs/
SRCS = $(addprefix ($SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)

bonus: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(RM) -r a.out a.out.dSYM leaks_result

re: fclean all

jko_test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS) test_main.c && ./a.out

.PHONY: jko_test bonus all clean fclean re
