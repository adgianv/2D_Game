#####   COLORS   #####

END				= \033[0m
GREY			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
PURPLE			= \033[35m
CYAN			= \033[36m
HIGH_RED		= \033[91m

#####   INFO   #####

NAME			= PAC-MAN
DESKTOP			= $(HOME)/Desktop
ICON_FILE		= icon.png

#####   COMMANDS   #####

CC				= gcc
EXTENSION		= c
CFLAGS			= -Wall -Wextra -Werror -g
MINILIBX		= make -C mlx
LINKER			= -framework OpenGL -framework AppKit
MLX				= mlx/libmlx.a

EXECUTION		= $(DESKTOP)/$(NAME)
MD				= mkdir -p
RM				= rm -rf
TAR_EXCLUSIONS	= --exclude=".git" \
				  --exclude=".vscode" \
				  --exclude="objs" \
				  --exclude="._" \
				  --exclude="*.DS_Store"
TAR				= tar $(TAR_EXCLUSIONS) -cf

#####   RESOURCES   #####

INCLUDE			= includes
SRC_DIR			= sources
OBJ_DIR			= objs

SRC_SUB_DIRS	= $(shell find $(SRC_DIR) -type d)
OBJ_SUB_DIRS	= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC_SUB_DIRS))

SRCS			= $(wildcard $(SRC_DIR)/*.$(EXTENSION))
OBJS			= ./sources/utils.o ./sources/exit.o ./printf/ft_putnbr.o ./printf/ft_printfutils.o ./printf/ft_printf.o ./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o ./sources/map.o ./sources/put_images.o ./sources/moves.o ./sources/so_long.o ./sources/enemy.o ./sources/chase.o ./sources/enemy_utils.o ./sources/check.o ./sources/enemy2.o ./sources/chase2.o ./sources/enemy_utils2.o ./sources/enemy3.o ./sources/chase3.o ./sources/enemy_utils3.o ./sources/enemy4.o ./sources/chase4.o ./sources/enemy_utils4.o

#####   BASE RULES   #####

all: $(NAME)

$(NAME): $(OBJS)
	@ $(MINILIBX)
	@ $(CC) $(MLX) $(LINKER) $(CFLAGS) $(OBJS) -o $(EXECUTION)
	@ echo "$(GREEN)[+] $(NAME) compiled$(END)"
	@ sips -i $(ICON_FILE)
	@ DeRez -only icns $(ICON_FILE) > $(NAME).rsrc
	@ Rez -append $(NAME).rsrc -o $(EXECUTION)
	@ SetFile -a C $(EXECUTION)
	@ rm $(NAME).rsrc
	@ echo "$(GREEN)[+] Icon added to $(NAME)$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXTENSION) | $(OBJ_SUB_DIRS)
	@ $(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@ echo "$(BLUE)[+] $@ compiled$(END)"

$(OBJ_SUB_DIRS):
	@ $(MD) $(OBJ_SUB_DIRS)
	@ echo "$(PURPLE)[+] $(SRC_DIR) remapped into $(OBJ_DIR)$(END)"

clean:
	@ $(RM) $(OBJS)
	@ echo "$(YELLOW)[+] $(OBJ_DIR) cleaned$(END)"

fclean: clean
	@ $(RM) $(EXECUTION)
	@ echo "$(YELLOW)[+] $(NAME) fcleaned$(END)"

re: fclean all

bonus: all

#####   PHONY   #####

.PHONY: all clean fclean re
