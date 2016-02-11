# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 11:40:18 by pkerckho          #+#    #+#              #
#    Updated: 2016/02/11 15:38:23 by pkerckho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fdf

SRC = main.c

obj = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft re
	@gcc $(FLAG) -o $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit libft/libft.a
	@echo "$(NAME) created"

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
