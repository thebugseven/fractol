CC = 		gcc
CFLAGS =	-Werror -Wextra -Wall
NAME =		fractol
SRC_FILES =	main\
			intialisation\
			utils\
			utils2\
			fractal/julia\
			fractal/mandelbrot\
			fractal/burningship\
			render\
			color\
			event\
			control\
			color2
SRC_DIR =	src/
OBJ_DIR =	obj/
INCLUDE =	./include/
MINILIB =	./minilibx-linux/
MLX =		$(MINILIB)/libmlx.a

SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -I $(INCLUDE) -I $(MINILIB) -lXext -lX11 -lm

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)fractal
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(MLX):
	@make -sC $(MINILIB)

$(OBJ): $(INCLUDE)fractol.h $(MINILIB)mlx.h $(INCLUDE)keycode.h

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(MINILIB)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re
