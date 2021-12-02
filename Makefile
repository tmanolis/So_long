# *--------- SOURCES ---------* 

SRCS_DIR = ./srcs/
SRCS = algorithm/sort_2_args.c							\
	
		
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

# *--------- includes ---------* 

INCLUDES_DIR = -I ./includes/header

# *--------- Libft ---------* 

LIBFT_DIR = ../includes/Libft
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# *--------- OTHERS ---------*

NAME = so_long

CC = clang
RM = rm -f

CFLAGS = -g -Wall -Wextra -Werror

# *========= RULES =========*

all:		$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES_DIR) 

$(NAME):	$(OBJS)
			make -C $(LIBFT_DIR)
	        $(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(INCLUDES_DIR) -o $(NAME)

clean:
			make -C $(LIBFT_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re