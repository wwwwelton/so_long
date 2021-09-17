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

OBJECTS			= 	$(SOURCES:.c=.o)

OBJECTS_BONUS	= 	$(SOURCES_BONUS:.c=.o)

NAME			=	libft.a

CC				=	clang
AR				=	ar
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
ARFLAGS 		=	rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJECTS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

bonus:			$(NAME) $(OBJECTS_BONUS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS_BONUS)

clean:
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
