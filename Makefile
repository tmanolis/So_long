# *--------- SOURCES ---------* 

SRCS_DIR = ./srcs/
SRCS = main.c								\
	events/handle.c							\
	events/move_player.c					\
	get_map/check_map_errors.c				\
	get_map/get_the_map.c					\
	get_map/init_map.c						\
	gnl/get_next_line.c						\
	gnl/get_next_line_utils.c				\
	graphics/get_images.c					\
	graphics/render.c						\
	utils/errors_and_free.c					\
		
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

# *--------- mlx_linux ---------*

MLX_DIR = ./mlx_linux
MFLAGS = -ldl -lmlx -Lmlx_linux -lm -lXext -lX11 -Imlx mlx_linux/libmlx.a

# *--------- includes ---------* 

INCLUDES_DIR = -I ./includes/header

# *--------- Libft ---------* 

LIBFT_DIR = ./includes/Libft
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# *--------- OTHERS ---------*

NAME = so_long

CC = clang
RM = rm -f

CFLAGS = -g -Wall -Wextra -Werror

# *========= RULES =========*

all:		$(NAME)

# $(CC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES_DIR) 

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			make -C $(LIBFT_DIR)
	        $(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(INCLUDES_DIR) -o $(NAME) $(MFLAGS)

clean:
			make -C $(MLX_DIR) clean
			make -C $(LIBFT_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re