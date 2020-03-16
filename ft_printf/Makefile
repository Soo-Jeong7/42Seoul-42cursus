# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 16:52:44 by jko               #+#    #+#              #
#    Updated: 2020/03/16 14:06:39 by jko              ###   ########.fr        #
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
	ft_printf_print_char

FILES_B = $(addsuffix _bonus, $(FILES))

SRC_DIR = ./srcs/
SRCS = $(addprefix ($SRC_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix ($SRC_DIR), $(addsuffix .c, $(FILES_B)))

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_B)))


$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

bonus: $(OBJS_B)
	$(AR) $(ARFLAGS) $(NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(RM) -r a.out a.out.dSYM leaks_result

re: clean all

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS) test_main.c && ./a.out

.PHONY: test bonus all clean fclean re
