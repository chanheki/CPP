# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:05:34 by chanheki          #+#    #+#              #
#    Updated: 2023/06/27 14:33:41 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- NAME ---- #

NAME		=	PmergeMe

CC			=	c++
STD			=	-std=c++98
CXXFLAGS	=	-Wall -Wextra -Werror $(STD) $(DBGS)
DBGS		=	-fsanitize=address -g3

RM			=	rm -rf

object_dir	=	./objects

# ---- TEST ---- #

EXEC		=	PmergeMe
TEST		=	test

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

sources1 :=	main.cpp

sources1 += PmergeMe.cpp

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

.PHONY : all bonus clean fclean re test leaks leak

all : $(NAME)

$(NAME) : $(objects_goal)
	@$(CC) $(CXXFLAGS) -o $(EXEC) $(objects_goal) 
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

bonus : $(NAME)

$(object_dir)/%.o : %.cpp
	@mkdir -p $(object_dir)/$(dir $^)
	@$(CC) $(CXXFLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

clean :
	@$(RM) $(all_objects)
	@rm -rf $(object_dir)
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(TEST)
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)
	
# ---- Test ---- #

leaks: CXXFLAGS += -D LEAKS
leaks: fclean all
	./$(EXEC)

dbg: CXXFLAGS += $(DBGS)
dbg: fclean all
	./$(EXEC)

test: all 
	./$(EXEC) 3 5 9 7 4

test1: all 
	./$(EXEC) 5 8 10 20 30 1 2 4 6 9 11 21 7

test2: all 
	./$(EXEC) 5 8 10 20 30 1 2 4 6 9 11 21 7 5

test3: all 
	./$(EXEC) 4 3 2 0

test4: all 
	./$(EXEC) 
	
test5: all
	./$(EXEC) `jot -r 3000 1 100000 | sort -uR `

test6: all
	./$(EXEC) `jot -r 10000 1 100000 | sort -uR `