# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 09:04:35 by cdrouet           #+#    #+#              #
#    Updated: 2017/01/15 14:48:14 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp \
	  Ncurse.class.cpp \
	  PlayerShip.class.cpp \
	  EnemyShip.class.cpp \
	  Shoot.class.cpp \
	  SpaceCraft.class.cpp \
	  BigShip.class.cpp \

BIN = $(SRC:.cpp=.o)

FLAG = -Wall -Wextra -Werror

Lib = -lncurses

$(NAME) :
	clang++ $(FLAG) -c $(SRC);
	clang++ $(FLAG) -o $(NAME) $(BIN) $(Lib)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean :
	rm -f $(BIN)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
