SOURCES			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c
SOURCES			+=	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
SOURCES			+=	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c
SOURCES			+=	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c
SOURCES			+=	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c
SOURCES			+=	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SOURCES			+=	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c
SOURCES			+=	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
SOURCES			+=	ft_tolower.c ft_toupper.c

SOURCES			+=	ft_free_ptr.c ft_str_replace.c ft_str_toupper.c
SOURCES			+=	ft_char_tostr.c ft_uitoa_base.c ft_get_next_line.c

SOURCES_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
SOURCES_BONUS	+=	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
SOURCES_BONUS	+=	ft_lstmap.c

HEADER			=	libft.h

OBJ_DIR			=	objects

OBJECTS			=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(SOURCES_BONUS:%.c=$(OBJ_DIR)/%.o)

NAME			=	libft.a
NAME_BONUS		=	libft_bonus.a

CC				=	clang
AR				=	ar
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
ARFLAGS 		=	rcs

$(OBJ_DIR)/%.o:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJ_DIR) $(OBJECTS) $(HEADER)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(NAME_BONUS):	$(NAME) $(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS_BONUS)
				cp $(NAME) $(NAME_BONUS)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re bonus
