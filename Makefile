NAME = my_containers
NAME1 = stl_containers
NAME2 = ft_containers
TEST_PATH = ./test

#original test
SRC = main.cpp tester_vector.cpp  tester_map.cpp tester_stack.cpp tester_set.cpp
SRC_PATH = $(addprefix $(TEST_PATH)/,$(SRC))
OBJ = $(SRC:.cpp=.o)

#binary
FT_DOSSIER = ./test1
FT_SRC = main.cpp test_vector.cpp  test_set.cpp test_stack.cpp test_map.cpp test_42.cpp
FT_PATH = $(addprefix $(FT_DOSSIER)/,$(FT_SRC))
OBJ1 = $(FT_SRC:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

BLINK=\e[5m
RED=\033[91m
ORANGE=\e[38;5;202m
PURPLE=\e[38;5;57m
BLUE=\033[94m
DARK_YELLOW=\033[0;33m
YELLOW=\033[93m
GREEN=\033[0;32m
NC=\033[0;0m

head:
	@echo "\n\n${RED}███╗   ███╗██╗ █████╗  ██████╗    ███╗   ███╗██╗ █████╗  ██████╗"
	@echo "${ORANGE}████╗ ████║██║██╔══██╗██╔═══██╗   ████╗ ████║██║██╔══██╗██╔═══██╗"
	@echo "${YELLOW}██╔████╔██║██║███████║██║   ██║   ██╔████╔██║██║███████║██║   ██║"
	@echo "${GREEN}██║╚██╔╝██║██║██╔══██║██║   ██║   ██║╚██╔╝██║██║██╔══██║██║   ██║"
	@echo "${BLUE}██║ ╚═╝ ██║██║██║  ██║╚██████╔╝   ██║ ╚═╝ ██║██║██║  ██║╚██████╔╝"
	@echo "${PURPLE}╚═╝     ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝    ╚═╝     ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝ ${NC}\n\n"
	@echo "\t\t    ${GREEN}${BLINK}${NAME} binary ready !!${NC}\n\n"

NAME:
	@$(CC) $(CFLAGS) $(SRC_PATH) -c
	@$(CC) $(OBJ) -o ${NAME}

NAME2:
	@$(CC) $(CFLAGS) $(FT_PATH) -D TESTED_NAMESPACE=ft -c
	@$(CC) $(OBJ1) -o ${NAME2}
NAME1:
	@$(CC) $(CFLAGS) $(FT_PATH) -D TESTED_NAMESPACE=std  -c
	@$(CC) $(OBJ1) -o ${NAME1}
all: NAME NAME2 NAME1 head
	@printf "\n${NC}⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"
	@printf "${BLUE}FT_CONTAINERS${NC}:    ${GREEN}Ready             ${YELLOW}----          ${NC}\n"
	@printf "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

clean:
	@/bin/rm -f ${OBJ} ${OBJ1} ./a.out
	@/bin/rm -rf test/vectors_output test/maps_output
fclean: clean
	@/bin/rm -f *~ ${NAME} ${NAME1} ${NAME2}
	@/bin/rm -f *#
	@/bin/rm -rf maps_output set_output vectors_output
re: fclean all
