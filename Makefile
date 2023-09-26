NAME	=	ft_printf.a
INC		=	ft_printf.h
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar rc
RM		=	rm -f

SRC		= 	ft_printf.c ft_printlhex.c ft_printuhex.c ft_putnbr.c \
			ft_putu.c ft_printptr.c ft_putchar.c ft_putstr_ptr.c

OBJS	=	$(SRC:.c=.o)

.PHONY	=	all clean fclearn re

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c	$(INC)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			clean all