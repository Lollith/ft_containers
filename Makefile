# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <agouet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:12:52 by agouet            #+#    #+#              #
#    Updated: 2023/01/04 18:04:44agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#make : creer ft_containers et std_containers avec le main du sujet
#make vector : ft_vector et std_vectors : test de mes vecteurs

################################################################################
#                                 tools
################################################################################

NAME			= ft_containers
NAME_STD		= std_containers

NAME_VECTOR_FT	= ft_vector
NAME_VECTOR_STD	= std_vector

CXX			= c++

RM			= rm -rf

MKDIR		= mkdir -p 

CXXFLAGS	= -MMD -Wall -Wextra -Werror -std=c++98 -fsanitize=address 

################################################################################
#                                 files
################################################################################

SRC_PATH		= sources/
OBJ_PATH 		= objects/

SRC				= $(addprefix $(SRC_PATH), main.cpp)
OBJ_FT				= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%_ft.o)
OBJ_STD			= $(SRC:${SRC_PATH}%.cpp=${OBJ_PATH}%_std.o)

SRC_VECTOR		= $(addprefix $(SRC_PATH), main_vector.cpp)
OBJ_VECTOR_FT	= $(SRC_VECTOR:${SRC_PATH}%.cpp=${OBJ_PATH}%_ft.o) #_ft.o
OBJ_VECTOR_STD	= $(SRC_VECTOR:${SRC_PATH}%.cpp=${OBJ_PATH}%_std.o)

DEPS			= ${OBJ_PATH}%.o=${OBJ_PATH}%.d) \
					 $(OBJ_VECTOR_FT:${OBJ_PATH}%.o=${OBJ_PATH}%.d)\
					 $(OBJ_VECTOR_STD:${OBJ_PATH}%.o=${OBJ_PATH}%.d)
#   pour check les .tpp passer par .o au lieu de .cpp

INC				= -I ./includes/

################################################################################
#                                rules
################################################################################

$(OBJ_PATH)%_ft.o	: $(SRC_PATH)%.cpp    #si _ft_o ou si _std.o => define FT
					$(MKDIR) ${dir $@}
					$(CXX) $(CXXFLAGS) $(INC) -DFT -c $< -o $@

$(OBJ_PATH)%_std.o	: $(SRC_PATH)%.cpp
					$(MKDIR) ${dir $@}
					$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@


all				: $(NAME) $(NAME_STD)

$(NAME)			: $(OBJ_FT)
					$(CXX) $(CXXFLAGS) $(OBJ_FT) -o $(NAME)

$(NAME_STD)		: $(OBJ_STD)
					$(CXX) $(CXXFLAGS) $(OBJ_STD) -o $(NAME_STD)


vector          : $(NAME_VECTOR_FT) $(NAME_VECTOR_STD) 

$(NAME_VECTOR_FT)	: $(OBJ_VECTOR_FT)
					$(CXX) $(CXXFLAGS) $(OBJ_VECTOR_FT) -o $(NAME_VECTOR_FT)

$(NAME_VECTOR_STD)	: $(OBJ_VECTOR_STD)
					$(CXX) $(CXXFLAGS) $(OBJ_VECTOR_STD) -o $(NAME_VECTOR_STD)


################################################################################
#                                clean
################################################################################

clean:
		$(RM) objects

fclean: clean
		$(RM) $(NAME) $(NAME_STD) $(NAME_VECTOR_FT) $(NAME_VECTOR_STD)  

re: fclean
	make -C .


################################################################################
#                                 utils
################################################################################

.PHONY: all re clean fclean

-include $(DEPS)
