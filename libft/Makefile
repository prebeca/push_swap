
LIBFT_NAME		=		libft.a

LIBFT_C_DIR		=		libft/src

LIBFT_O_DIR		=		obj/obj_libft

LIBFT_SRCS		=		${patsubst %, ${LIBFT_C_DIR}/%, ${LIBFT_C_FILES}}

LIBFT_C_FILES	=		get_next_line.c\
						ft_strrchr.c\
						ft_putendl_fd.c\
						ft_memmove.c\
						ft_lstdelone.c\
						ft_isprint.c\
						ft_strlcpy.c\
						ft_strtrim.c\
						ft_putnbr_fd.c\
						ft_memset.c\
						ft_lstiter.c\
						ft_atoi.c\
						ft_strclen.c\
						ft_substr.c\
						ft_putstr_fd.c\
						ft_memcmp.c\
						ft_lstlast.c\
						ft_bzero.c\
						ft_memchr.c\
						ft_strlen.c\
						ft_split.c\
						ft_lstnew.c\
						ft_lstmap.c\
						ft_calloc.c\
						ft_tolower.c\
						ft_strmapi.c\
						ft_strchr.c\
						ft_lstsize.c\
						ft_itoa.c\
						ft_isalnum.c\
						ft_toupper.c\
						ft_strjoin.c\
						ft_strcmp.c\
						ft_memccpy.c\
						ft_lstadd_back.c\
						ft_isalpha.c\
						ft_strncmp.c\
						ft_strlcat.c\
						ft_strdup.c\
						ft_lstadd_front.c\
						ft_isascii.c\
						ft_strnstr.c\
						ft_putchar_fd.c\
						ft_memcpy.c\
						ft_lstclear.c\
						ft_isdigit.c

LIBFT_OBJS	=			${patsubst ${LIBFT_C_DIR}/%, ${LIBFT_O_DIR}/%, ${LIBFT_SRCS:.c=.o}}

LIBFT_INC	=			-I./libft/

all:					${LIBFT_NAME}

$(LIBFT_NAME):			${LIBFT_OBJS}
						ar rc ${LIBFT_NAME} ${LIBFT_OBJS}


${LIBFT_O_DIR}/%.o :	${LIBFT_C_DIR}/%.c
						@mkdir -p ${LIBFT_O_DIR}
						${CC} ${LIBFT_INC} ${CFLAGS} -c $< -o $@