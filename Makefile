NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

SRCS = src/so_long.c src/controls.c src/maps.c src/free.c src/render.c\
        src/move.c  src/floodfill.c gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT_PATH = libft/

LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

PRINTF_PATH = printf/

PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

COMPILE_FLAGS = -I/usr/include -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -Ignl -O3

LINK_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJECTS = $(SRCS:.c=.o)

all: libraries $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -o $@

libraries:
	@echo Compiling libraries...
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all
	make -C $(PRINTF_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINK_FLAGS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libraries
