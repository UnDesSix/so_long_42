NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
AR 			=	ar
ARFLAGS 	=	rcs
RM			=	rm -rf

INC_PATH 	=	.
INC_NAME	=	libft.h
SRC_PATH 	= 	.
SRC_NAME 	=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SRC_NAME_BONUS	=	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c

INC 		=		$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC 		=		$(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC_BONUS	=		$(addprefix $(SRC_PATH)/, $(SRC_NAME_BONUS))

.SUFFIXES	: 		.c .o .h

_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c

OBJ 		=	 	$(SRC:.c=.o)
OBJ_BONUS	=		${SRC_BONUS:.c=.o}

all			:		$(NAME)
					@ echo "$(_SUCCESS) Libft compiled"

$(NAME)		:		$(OBJ) $(INC)
					@ $(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o			: 		%.c
					@ $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
					@ echo "$(_CLEAR)"

bonus		:		$(OBJ_BONUS) $(OBJ) $(INC)
					@ echo "$(_INFO) Initialize bonus $(NAME)"
					@ echo "$(_SUCCESS) Libft compiled with bonus"
					@ $(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

clean		:
					@ $(RM) $(OBJ) ${OBJ_BONUS}

fclean		:		clean
					@ $(RM) $(NAME)

re			: 		fclean all

.PHONY		:		all bonus clean fclean re
