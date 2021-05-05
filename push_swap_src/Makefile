PS_NAME		=		push_swap

PS_C_DIR	=		push_swap_src/src

PS_O_DIR	=		obj/obj_push_swap

PS_SRCS		=		${patsubst %, ${PS_C_DIR}/%, ${PS_C_FILES}}

PS_C_FILES	=		main.c \
					pivot.c\
					stack.c \
					sorter.c \
					checker.c \
					stack_clear.c\
					sorter_utils.c\
					check_limits.c\
					operations.c

PS_OBJS		=		${patsubst ${PS_C_DIR}/%, ${PS_O_DIR}/%, ${PS_SRCS:.c=.o}}

PS_INC		=		-I./push_swap_src/inc/

all:				${PS_NAME}

${PS_NAME}:	${PS_OBJS} ${LIBFT_NAME}
			${CC} ${PS_INC} ${CFLAGS} ${PS_OBJS} ${LIBS} -o ${PS_NAME}

${PS_O_DIR}/%.o :	${PS_C_DIR}/%.c
					@mkdir -p ${PS_O_DIR}
					${CC} ${PS_INC} ${CFLAGS} -c $< -o $@