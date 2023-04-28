NAME					= libftprintf.a

SRCS					= ft_printf.c \
						ft_printf_utils.c \
						ft_printf_utils2.c \
						ft_printf_utils3.c
OBJS					= $(SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)		:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o			: %.c
	gcc $(FLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re