NAME = ft_containers

TEST_PATH = ./test

SRC = main.cpp tester_vector.cpp  tester_map.cpp tester_stack.cpp tester_set.cpp

SRC_PATH = $(addprefix $(TEST_PATH)/,$(SRC))

OBJ = $(SRC:.cpp=.o)

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

${NAME}:
	@$(CC) $(CFLAGS) $(SRC_PATH) -c
	@$(CC) $(OBJ) -o ${NAME}
	@echo "\n\n${RED}███╗   ███╗██╗ █████╗  ██████╗    ███╗   ███╗██╗ █████╗  ██████╗"
	@echo "${ORANGE}████╗ ████║██║██╔══██╗██╔═══██╗   ████╗ ████║██║██╔══██╗██╔═══██╗"
	@echo "${YELLOW}██╔████╔██║██║███████║██║   ██║   ██╔████╔██║██║███████║██║   ██║"
	@echo "${GREEN}██║╚██╔╝██║██║██╔══██║██║   ██║   ██║╚██╔╝██║██║██╔══██║██║   ██║"
	@echo "${BLUE}██║ ╚═╝ ██║██║██║  ██║╚██████╔╝   ██║ ╚═╝ ██║██║██║  ██║╚██████╔╝"
	@echo "${PURPLE}╚═╝     ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝    ╚═╝     ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝ ${NC}\n\n"
	@echo "\t\t    ${GREEN}${BLINK}${NAME} binary ready !!${NC}\n\n"

all: ${NAME}
	@printf "\n${NC}⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"
	@printf "${BLUE}FT_CONTAINERS${NC}:    ${GREEN}Ready             ${YELLOW}----          ${NC}\n"
	@printf "⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

clean:
	@/bin/rm -f ${OBJ}
	@/bin/rm -rf test/vectors_output test/maps_output
fclean: clean
	@/bin/rm -f *~ ${NAME}
	@/bin/rm -f *#
	@/bin/rm -rf maps_output set_output vectors_output
re: fclean all
