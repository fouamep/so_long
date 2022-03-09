# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 17:48:52 by fbouanan          #+#    #+#              #
#    Updated: 2022/03/06 17:48:53 by fbouanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

all : $(NAME)

src =  so_long.c \
	so_long_utils.c \
	so_long_utils2.c \
	movePlayer.c \
	read_map.c \
	get_next_line.c \
	check_map.c \
	check_map_funcs.c \
	moves.c

so_long:
		gcc -Wall -Wextra -Werror -I /usr/local/include $(src) -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o so_long
clean :
	rm -f $(NAME)
fclean : clean

re : fclean all
