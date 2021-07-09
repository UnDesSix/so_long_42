NAME		=	so_long
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRC_DIR 	= 	srcs
SRC			=	$(notdir $(shell find $(SRC_DIR) -type f -name *.c))

LIBFT_DIR	=	libft
LIB_FLAG	=	-L $(LIBFT_DIR)

OBJ_DIR		=	srcs/obj
OBJ 		= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INC_DIR		=	includes
INC			=	$(shell find $(INC_DIR) -type f -name "*.h")

IFLAGS 		=	-I $(INC_DIR)

vpath			%.c $(shell find $(SRC_DIR) -type d)
.SUFFIXES: 		.c .o .h

_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c

all				:	init $(NAME)
					@ echo "$(_SUCCESS) Compilation done"

init			:
					@ mkdir -p $(OBJ_DIR)


$(NAME)			:	$(OBJ) $(INC)
					@ echo "$(_INFO) Initialize $(NAME)"
					@ $(CC) $(CFLAGS) $(OBJ) mlx_linux/libmlx.a -Lmlx_linux \
						-L/usr/lib -lXext -lX11 -lm -o $(NAME) $(LIB_FLAG)

$(OBJ_DIR)/%.o	:	%.c
					@ echo "\t$(_YELLOW)Compiling$(_RESET) $*.c\r\c"
					@ $(CC) $(CFLAGS) $(IFLAGS) -Imlx_linux -c $< -o $@
					@ echo "$(_CLEAR)"

clean			:
					@ echo "$(_INFO) Deleted object files and directories"
					@ $(RM) $(OBJ_DIR)
					@ echo "$(_SUCCESS) Working directory clean"

fclean			:	clean
					@ $(RM) $(NAME)

re				: 	fclean all

.PHONY: 		all fclean clean re init libft
