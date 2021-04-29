include libft/Makefile
include checker_src/Makefile
include push_swap_src/Makefile

CC		=	clang

CFLAGS	=	-g -Wall -Wextra -Werror

LIBS	=	libft.a

O_DIR	=	obj

.PHONY:		clean fclean re .c.o all

clean:
			rm -rf ${O_DIR}

fclean:		clean
			rm -f ${LIBFT_NAME} ${CHECKER_NAME} ${PS_NAME}
			rm -rf ${O_DIR}

re:			fclean all