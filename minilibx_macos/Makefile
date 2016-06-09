#
#

NAME = libmlx.a

SRC =	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
		mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)

CFLAGS += -O2

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mCreation de l'archive $@.\033[0m"
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "\033[35mSuppression des objets.\033[0m"
	@echo "\033[31mSuppression du fichier $(NAME).\033[0m"
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all
