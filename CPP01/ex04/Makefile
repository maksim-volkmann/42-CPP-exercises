# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 14:48:08 by mvolkman          #+#    #+#              #
#    Updated: 2024/08/29 09:45:16 by mvolkman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
