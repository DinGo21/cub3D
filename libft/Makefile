NAME = libft.a

LIB = ar rcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC_DIR = src/
PRINTF_DIR = ft_printf/
BONUS_DIR = bonus/
GNL_DIR = get_next_line/
OBJ_DIR = obj/
INC_DIR = include/

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
PRINTF_FILES = $(notdir $(wildcard $(PRINTF_DIR)*.c))
GNL_FILES = $(notdir $(wildcard $(GNL_DIR)*.c))
BONUS_FILES = $(notdir $(wildcard $(BONUS_DIR)*.c))
OBJ_FILES = $(SRC_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(GNL_FILES:.c=.o)
OBJ_BONUS_FILES = $(BONUS_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_BONUS_FILES))

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

bonus: obj $(OBJ_BONUS) $(OBJ)
	@$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
