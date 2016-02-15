# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 11:40:18 by pkerckho          #+#    #+#              #
#    Updated: 2016/02/15 16:14:03 by pkerckho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) $(INCL_DIR)

NAME = fdf

INC_DIR = includes
INCL = libft/includes/libft.h

SRC = main.c \
	  ft_parse.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB) -lmlx -framework OpenGL -framework AppKit libft/libft.a
	@echo "$(NAME) created"

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
