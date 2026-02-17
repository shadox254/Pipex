NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
OBJ_DIR		=	obj

LIB_SRCS	=	ft_isdigit.c \
				ft_putchar.c \
				ft_split.c \
				ft_strncmp.c \
				ft_isprint.c \
				ft_putchar_fd.c \
				ft_strchr.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_itoa.c \
				ft_putendl_fd.c \
				ft_strdup.c \
				ft_strrchr.c \
				ft_bzero.c \
				ft_memchr.c \
				ft_putlonglong_base.c \
				ft_striteri.c \
				ft_strtrim.c \
				ft_calloc.c \
				ft_memcmp.c \
				ft_putnbr_base.c \
				ft_strjoin.c \
				ft_substr.c \
				ft_intlen.c \
				ft_memcpy.c \
				ft_putnbr.c \
				ft_strlcat.c \
				ft_tolower.c \
				ft_isalnum.c \
				ft_memmove.c \
				ft_putnbr_fd.c \
				ft_strlcpy.c \
				ft_toupper.c \
				ft_isalpha.c \
				ft_memset.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_isascii.c \
				ft_printf_fd.c \
				ft_putstr_fd.c \
				ft_strmapi.c \
				ft_atol.c \
				ft_free_tab.c

LIB_OBJS	=	$(addprefix $(OBJ_DIR)/, $(LIB_SRCS:.c=.o))

GREEN		=	\033[32m
BLUE		=	\033[34m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(LIB_OBJS)
	@ar rcs $(NAME) $(LIB_OBJS)
	@echo "$(BLUE)libft compiled$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)$< compiled$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re