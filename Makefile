NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc 

INC		= ./includes/ft_printf.h

SRCS	= ft_printf.c ./includes/ft_atoi.c ./includes/ft_struzero.c \
		  ./includes/ft_putchar.c ./includes/ft_putnbr.c ./includes/ft_intlen.c	\
		  ./includes/ft_putstr.c ./includes/ft_strchr.c ./includes/ft_strlen.c \
		  ./includes/ft_integers.c ./includes/ft_isalpha.c \
		  ./includes/ft_parcer.c ./includes/ft_integers_negative.c \
		  ./includes/ft_integers_u.c ./includes/ft_x.c ./includes/ft_dex_hex.c ./includes/ft_char.c \
		  ./includes/ft_string.c ./includes/ft_percent.c ./includes/ft_p.c ./includes/ft_chosen_one.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib ${NAME}
	
all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
	
	
clean:
	-rm -rf $(OBJS) 

fclean: clean	
	-rm -rf $(NAME)
	
re:		fclean all

.PHONY: all clean fclean re
