WHITE			= \033[1;37m
GREY 			= \033[1;90m
GREEN			= \033[0;32m
PURPLE			= \033[0;34m
PINK			= \033[0;35m
BLINK			= \033[5m
END				= \033[0m


NAME			= warehouse

SRC_DIR			= src/
CONTAINERS_DIR	= $(SRC_DIR)Containers/

INCLUDES		= -Iinc \
					-Iinc/Containers

SRC				= 	main.cpp \
					$(addprefix $(SRC_DIR), Warehouse.cpp AMaterial.cpp Observer.cpp) \
					$(addprefix $(CONTAINERS_DIR), Iron.cpp Copper.cpp Lumisteel.cpp)

OBJ				= $(SRC:.cpp=.o)
CXX				= @c++
CXXFLAGS 		= -g3 -Wall -Wextra -Werror $(INCLUDES) #-fsanitize=address

RM				= rm -rf

all:		$(NAME)


$(NAME):	Makefile
			@printf "$(GREY)Compiling the $(END)$(WHITE)$(NAME)..."
			@$(MAKE) -s $(OBJ)
			@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
			@printf " $(GREY)Greetings traveler $(END)$(BLINK)✧₊⁺ $(BLINK)$(END)\n\n"

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@printf "$(GREY)Clearing the path, leaving no trace of the past adventures...$(END)\n\n"

re:			fclean $(NAME)

.PHONY:		all clean fclean re