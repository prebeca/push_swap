CHECKER_NAME	=		checker

CHECKER_C_DIR	=		checker_src/src

CHECKER_O_DIR	=		obj/obj_checker

CHECKER_SRCS	=		${patsubst %, ${CHECKER_C_DIR}/%, ${CHECKER_C_FILES}}

CHECKER_C_FILES	=		main.c \
						checker.c\
						operations.c\
						check_limits.c\
						read_instructions.c\
						apply_instructions.c

CHECKER_OBJS	=		${patsubst ${CHECKER_C_DIR}/%, ${CHECKER_O_DIR}/%, ${CHECKER_SRCS:.c=.o}}

CHECKER_INC		=		-I./checker_src/inc/

all:					${CHECKER_NAME}

${CHECKER_NAME}:		${CHECKER_OBJS} ${LIBFT_NAME}
						${CC} ${CHECKER_INC} ${CFLAGS} ${CHECKER_OBJS} ${LIBS} -o ${CHECKER_NAME}

${CHECKER_O_DIR}/%.o :	${CHECKER_C_DIR}/%.c
						@mkdir -p ${CHECKER_O_DIR}
						${CC} ${CHECKER_INC} ${CFLAGS} -c $< -o $@