# Variables
NAME    = Bureaucrat
SRC     = Main.cpp Bureaucrat.cpp
OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing executable $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re