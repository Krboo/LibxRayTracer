# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 15:47:16 by pmartine          #+#    #+#              #
#    Updated: 2016/10/24 13:44:35 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv1

CFLAGS = -Wall -Werror -Wextra -I includes

SRC = srcs/parsing/camera.c srcs/parsing/clear.c srcs/parsing/color.c \
	  srcs/parsing/cone.c srcs/parsing/cylindre.c srcs/parsing/init.c\
	  srcs/parsing/plan.c srcs/parsing/tools_vect.c srcs/parsing/sphere.c\
	  srcs/parsing/spot.c \
	  srcs/draw.c srcs/hook.c srcs/main.c srcs/objects.c srcs/vectors.c\

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

demo :
	./Rtv1 scene/demo.1

.PHONY: all clean fclean re
