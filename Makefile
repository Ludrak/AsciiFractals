
NAME=ascii_fractals

SRC_DIR=src
SRCS=main.c ascii_screen.c ascii_palette.c mandelbrot.c julia.c utils.c math.c executor.c

INC_DIR=inc
INCLUDES=mandelbrot.h utils.h ascii_screen.h

BIN_DIR=bin
OBJS=$(SRCS:%.c=$(BIN_DIR)/%.o)
HEADERS=$(addprefix $(INC_DIR)/, $(INCLUDES))

CFLAGS=-Wextra -Wall -Werror

all: $(NAME)
	@echo Done.

$(NAME) : $(BIN_DIR) $(OBJS)
	@gcc -o $@ $(OBJS)
	@echo "linked project : $(NAME)"

$(BIN_DIR) :
	@mkdir -p $@

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c
	@gcc -c -o $@ $(INC_DIR:%=-I%) $(CFLAGS) $<
	@echo "compiled : $@"

clean:
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all