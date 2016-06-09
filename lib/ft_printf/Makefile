# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 08:47:42 by kdezaphi          #+#    #+#              #
#    Updated: 2016/06/09 11:50:53 by kdezaphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/
SRC =	ft_backslash.c ft_bintoint.c ft_flags.c ft_llbtoa.c ft_lltoa.c \
		ft_padpos.c ft_printf.c ft_type.c ft_typec.c ft_typed.c \
		ft_typenumeric.c ft_typeo.c ft_types.c ft_typestr.c ft_typeu.c \
		ft_typewc.c ft_typews.c ft_typex.c ft_dprintf.c ft_sqrt.c

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -I../incs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "\033[32mCreation de l'archive $@.\033[0m"
	@ar -rc $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "\033[34mCreation du fichier objet $@.\033[0m"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[35mSuppression des objets.\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mSuppression du fichier $(NAME).\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
