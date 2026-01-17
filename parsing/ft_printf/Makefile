NAME = libftprintf.a
CC = cc
HEADER = ft_printf.h
SRC = ft_printf.c ft_hexutils.c ft_strlen.c ft_putchar.c ft_calloc.c \
	  ft_putnbr.c ft_putnbr_un.c ft_putstr.c
CFLAGS = -Werror -Wextra -Wall
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFALGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
