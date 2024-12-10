NAME = libftprintf.a

SRCS = ft_printf.c functions.c 

OBJS = $(SRCS:.c=.o)

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
