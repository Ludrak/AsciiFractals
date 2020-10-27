
NAME=mandelbrot.out

SRC_DIR=src
SRCS=main.c ascii_screen.c ascii_palette.c mandelbrot.c utils.c

INC_DIR=inc
INCLUDES=mandelbrot.h utils.h ascii_screen.h

BIN_DIR=bin
OBJS=$(SRCS:%.c=$(BIN_DIR)/%.o)
HEADERS=$(addprefix $(INC_DIR)/, $(INCLUDES))

CFLAGS=-Werror -Wextra -Wall# -g3 -fsanitize=address

all: $(NAME)
	@echo Done.

$(NAME) : $(BIN_DIR) $(OBJS)
	@gcc -o $@ $(OBJS) -lm -g3 #-fsanitize=address
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