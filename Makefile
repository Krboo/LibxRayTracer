# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 15:47:16 by pmartine          #+#    #+#              #
#    Updated: 2016/10/13 18:19:01 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv1

CFLAGS = -Wall -Werror -Wextra -I includes

SRC = srcs/main.c srcs/draw.c srcs/hook.c srcs/vectors.c srcs/objects.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h -lmlx \
	-framework OpenGl -framework Appkit libft/libft.a minilibx_macos/libmlx.a
	@echo "Make libmlx.a: \033[1;32m DONE !\033[m"
	@echo "Make $(NAME) : \033[1;32m DONE !\033[m"

clean :
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -rf $(OBJ)
	@echo "Clean Libft, Minilibx and $(NAME) : \033[1;32m DONE !\033[m"

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "Fclean $(NAME) : \033[1;32m DONE !\033[m"

re : fclean all

yo :
	./Rtv1 yo

.PHONY: all clean fclean re
