NAME		=	so_long
CC			=	clang -Wall -Werror -Wextra
RM			=	rm -rf

MLX_PATH	=	./minilibx-linux/
MLX_NAME	=	$(MLX_PATH)libmlx.a
MLX_INC		=	-I$(MLX_PATH)

LIBC_PATH	=	./libft/
LIBC_NAME	=	$(LIBC_PATH)libft.a
LIBC_INC	=	-I$(LIBC_PATH)

SRCS_PATH	=	./srcs/
OBJS_PATH	=	./objs/
INC			=	./includes/

SRCS_NAME	=	main.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			@$(CC) -I$(INC) $(MLX_INC) $(LIBC_INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make --silent -C $(MLX_PATH)
			@make --silent -C $(LIBC_PATH)
			@$(CC) $(OBJS) $(MLX_NAME) $(LIBC_NAME) -L$(MLX_PATH) -L/usr/lib -L$(LIBC_PATH) $(LIBC_INC) $(MLX_INC) -I$(INC) -lXext -lX11 -lm -o $(NAME) 

clean:
			@make clean --silent -C $(LIBC_PATH)
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean --silent -C $(LIBC_PATH)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		re fclean all clean
