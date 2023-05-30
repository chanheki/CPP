# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:05:34 by chanheki          #+#    #+#              #
#    Updated: 2023/01/19 22:53:55 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- NAME ---- #

NAME		=	megaphone

CC			=	c++
STD			=	-std=c++98
CFLAGS		=	-Wall -Wextra -Werror $(STD)
DBGS		=	-fsanitize=address -g3

RM			=	rm -rf

object_dir	=	./objects

# ---- TEST ---- #

EXEC		=	megaphone

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Mandatory ---- #

sources1 :=	

sources1 += megaphone.cpp

# ---- Bonus ---- #

sources2 :=	

# ---- Elements ---- #

all_sources = $(sources1) $(sources2)

objects1 = $(sources1:.cpp=.o)
objects2 = $(sources2:.cpp=.o)
all_objects = $(objects1) $(objects2)

define objects_goal
$(addprefix $(object_dir)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), objects2, objects1))) 
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

# ---- Command ---- #

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(objects_goal)
	@$(CC) $(CFLAGS) -o $@ $(objects_goal)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

bonus : $(NAME)

$(object_dir)/%.o : %.cpp
	@#mkdir -p $(object_dir)
	@mkdir -p $(object_dir)/$(dir $^)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

clean :
	@$(RM) $(all_objects)
	@rm -rf $(object_dir)
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)

test1: all
	./$(EXEC) "shhhhh... I think the students are asleep..."

test2: all
	./$(EXEC) Damnit " ! " "Sorry students, I thought this thing was off."

test3: all
	./$(EXEC)