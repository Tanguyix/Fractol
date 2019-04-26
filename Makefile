NAME = fractol
SRC = 	main.c \
		exit_usage.c \
		mlx.c \
		events.c \
		ft_mandel.c \
		ft_julia.c \
		ft_burning.c \
		ft_init.c \
		colors.c \
		ft_tricorn.c \
		zoom.c \
		ft_tutorial.c
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
CC = gcc
LIB = libft
FRAME = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
LIBDONE = libft/libft.a

all: lib $(NAME)

lib :
	$(MAKE) -C $(LIB)

$(NAME): $(OBJ)
	$(CC) -O3 $(FLAGS) $(OBJ) $(LIBDONE) $(FRAME) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean	

re: fclean all
