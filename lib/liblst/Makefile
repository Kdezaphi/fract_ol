# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 16:06:44 by kdezaphi          #+#    #+#              #
#    Updated: 2016/06/09 13:20:34 by kdezaphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblst.a

SRC_DIR = srcs/
SRC =	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstaddlast.c \
		ft_lstiter.c ft_lstmap.c ft_lstdblnew.c ft_lstdbladd.c \
		ft_lstdbladd_first.c ft_lstdbladd_last.c ft_initdef.c ft_lstdbldel.c \
		ft_lstdbldelone.c

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
