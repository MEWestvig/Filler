# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 10:52:28 by mwestvig          #+#    #+#              #
#    Updated: 2018/06/23 18:16:01 by mwestvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/mwestvig.filler

FLAGS = -Wall -Werror -Wextra -I includes

SRCS = srcs/filler.c \
	   srcs/set_info.c \

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
