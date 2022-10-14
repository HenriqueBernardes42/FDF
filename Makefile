NAME = fdf
SRC_DIR = ./src/
HEADER_DIR = ./includes/
OBJ_DIR = ./obj/
LIBFT_DIR = ./LIBFT/

LIBFT_H = $(LIBFT_DIR)
SRC_FILES = \
	linked_lists.c \
	set_line.c \
	useful_functions.c \
	fdf.c \
	creating_wires.c \
	to_free.c

HEADER_FILES = func_header.h 
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILES))
INCLUDES = -I $(HEADER_DIR) -I $(LIBFT_H)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(LIBFT_DIR)libft.a

CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBRARIES = -lmlx -lX11 -lXext -lm 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBRARIES) $(INCLUDES) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C LIBFT all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C LIBFT fclean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

PHONY: all clean fclean re
