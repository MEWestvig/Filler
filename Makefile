# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 10:52:28 by mwestvig          #+#    #+#              #
#    Updated: 2018/08/01 00:50:48 by mwestvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mwestvig.filler

FLAGS = -Wall -Werror -Wextra -I includes

SRCS = srcs/filler.c \
	   srcs/set_info.c \
	   srcs/check_positions.c \
	   srcs/algo.c \
	   srcs/freeing.c \
	   srcs/minialgo.c \
	   srcs/visual.c \

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
