# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 15:08:18 by kdezaphi          #+#    #+#              #
#    Updated: 2016/06/09 11:52:05 by kdezaphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libftprintf libft liblst

all: $(LIB)

libftprintf:
	@make -C ft_printf
	@cp ft_printf/libftprintf.a .

libft:
	@make -C libft
	@cp libft/libft.a .

liblst:
	@make -C liblst
	@cp liblst/liblst.a .

clean:
	@make -C ft_printf clean
	@make -C libft clean
	@make -C liblst clean

fclean: clean
	@make -C ft_printf fclean
	@make -C libft fclean
	@make -C liblst fclean
	@rm -f $(LIB:=.a)

re: fclean all

.PHONY: all libftprintf libft liblst clean fclean re
