NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MAKE_CUR = make -C
MLX_DIR = ./minilibx
MLX = ./minilibx/libmlx.a
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
SRCS = ./src/main.c \
		./src/hook.c \
		./src/render.c \
		./src/utils.c \
		./src/error.c \
		./src/check.c \
		./src/init.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -L./minilibx -lmlx -L./libft -lft

all : $(NAME)

$(NAME) : make_mandatory

make_mandatory : $(OBJS)
	$(MAKE_CUR) $(MLX_DIR)
	$(MAKE_CUR) $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -framework OpenGL -framework AppKit -o $(NAME)
	@ touch make_mandatory

%.o : %.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(MAKE_CUR) $(MLX_DIR) clean
	$(MAKE_CUR) $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	@ $(RM) make_mandatory

fclean : clean
	$(MAKE_CUR) $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
