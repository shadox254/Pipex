# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 13:31:49 by rruiz             #+#    #+#              #
#    Updated: 2026/02/17 13:31:51 by rruiz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a
OBJ_DIR		= obj

SRCS		=	src/pipex.c \
				src/utils.c \
				src/create_path.c

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re