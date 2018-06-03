# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 20:39:15 by ldehaudt          #+#    #+#              #
#    Updated: 2018/05/16 16:35:36 by ldehaudt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

MINILIB = -I minilibx -L minilibx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = main.c color.c read.c my_math.c get_point.c draw_map.c draw_line.c

HEADER = fdf.h

LIBRARY = -L ./libft -lft

all : $(NAME)

$(NAME) : 
	gcc $(FLAGS) $(LIBRARY) $(MINILIB) -lmlx $(FRAMEWORKS) -I $(HEADER) $(SRC) -o $(NAME)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
