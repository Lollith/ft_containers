# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:12:52 by agouet            #+#    #+#              #
#    Updated: 2022/12/29 16:25:50 by agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_containers
NAME_VECTOR = ft_vector

CXX			= c++

RM			= rm -rf

MKDIR		= mkdir -p 



SRC_PATH	= sources/

SRC			= $(addprefix $(SRC_PATH), main.cpp)
SRC_VECTOR	= $(addprefix $(SRC_PATH), main_vector.cpp)

OBJ_PATH 	= objects/

OBJ					= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%.o)
OBJ_VECTOR			= $(SRC_VECTOR:${SRC_PATH}%.cpp=${OBJ_PATH}%.o)

DEPS		= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%.d)
DEPS_VECTOR	= $(SRC_VECTOR:${SRC_PATH}%.cpp=${OBJ_PATH}%.d)

CXXFLAGS	= -MMD -Wall -Wextra -Werror -std=c++98 -fsanitize=address 

INC			= -I ./includes/



all				: $(NAME)
vector          : $(NAME_VECTOR)

$(OBJ_PATH)%.o	: $(SRC_PATH)%.cpp
					$(MKDIR) ${dir $@}
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME)			: $(OBJ)
					$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(NAME_VECTOR)	: $(OBJ_VECTOR)
					$(CXX) $(CXXFLAGS) $(OBJ_VECTOR) -o $(NAME_VECTOR)


clean:
		$(RM) objects

fclean: clean
		$(RM) $(NAME) $(NAME_VECTOR)

re: fclean
	make -C .

.PHONY: all re clean fclean

-include $(DEPS) $(DEPS_VECTOR)

