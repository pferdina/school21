# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pferdina <pferdina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 16:57:15 by ndaniell          #+#    #+#              #
#    Updated: 2019/11/07 17:38:53 by pferdina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/*.c
OBJ = ./src/*.o
FLAG = -Wall -Wextra -Werror

LIBFT = libft/
all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc -g $(FLAG) -o $(NAME) $(SRC) -L $(LIBFT) -lft

clean:
	@rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all

.PHONY: all, clean, fclean, re
