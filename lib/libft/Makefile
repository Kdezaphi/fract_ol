# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 16:17:46 by kdezaphi          #+#    #+#              #
#    Updated: 2016/06/09 11:46:45 by kdezaphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = srcs/
SRC =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_isupper.c ft_toupper.c ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_nblen.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_dup_join.c ft_isspace.c ft_islower.c get_next_line.c ft_dtoa.c \
		ft_dec.c ft_intp.c ft_addret.c

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
