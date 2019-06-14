NAME = fdf
FLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx_macos
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

INCL = incl/
LIBFT_DIR = libft/

SRC_DIR = ./srcs/
SRC = main.c \
	image.c \
	read.c \
	debug.c

FILES = $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling libft"
	@make -C $(LIBFT_DIR)
	@echo "Compiling minilibx"
	@make -C $(MLX_DIR)
	@echo "Creating binary file."
	@#ADD BACK THE FLAGS DOWN THERE
	@gcc $(FLAGS) -L./libft/ -lft $(MLX) $(OBJ) -o $(NAME)
	@echo "Cleaning libft"

$(OBJ_DIR)%.o: srcs/%.c
	@#ADD BACK THE FLAGS DOWN THERE
	@echo "Compiling $@"
	@mkdir -p $(dir $@) && gcc $(FLAGS) -c $< -o $@

clean :
	@echo "Removing .o files."
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@echo "Removing binary file."
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
