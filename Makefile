# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:12:52 by agouet            #+#    #+#              #
#    Updated: 2022/12/22 17:51:53 by agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_vector

CXX			= c++

RM			= rm -rf

MKDIR		= mkdir -p 



SRC_PATH	= sources/

SRC			= $(addprefix $(SRC_PATH), main.cpp)

OBJ_PATH 	= objects/

OBJ			= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%.o)

DEPS		= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%.d)

CXXFLAGS	= -MMD -Wall -Wextra -Werror -std=c++98 -fsanitize=address 

INC			= -I ./includes/



all				: $(NAME)

$(OBJ_PATH)%.o	: $(SRC_PATH)%.cpp
					$(MKDIR) ${dir $@}
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME)			: $(OBJ)
					$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


clean:
		$(RM) objects

fclean: clean
		$(RM) $(NAME)

re: fclean
	make -C .

.PHONY: all re clean fclean

-include $(DEP)

