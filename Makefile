SRC = test/main.cpp test/tester_vector.cpp  test/tester_map.cpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f *~ ./a.out
	@/bin/rm -f *#
	@/bin/rm -rf vectors_output maps_output
re: fclean all
