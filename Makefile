SRCS		= parsing/ft_add_objects.c parsing/ft_add_forms.c srcs/main.c \
			parsing/ft_ato.c parsing/get_next_line.c parsing/get_next_line_utils.c \
			parsing/parsing.c parsing/objects.c parsing/forms.c parsing/forms2.c parsing/error.c \
			send_ray/utils_calcul.c send_ray/sphere.c send_ray/utils_rays.c send_ray/intersection.c \
			send_ray/functions_light.c send_ray/utils_others.c send_ray/shadows.c send_ray/plane.c

OBJS		= ${SRCS:.c=.o}

NAME		= a.out

INCS		= -I srcs/header.h 

CC			= gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM			= rm -rf

.c.o:		${CC} -c $< -o ${<:.c=.o}

${NAME}:	
			${CC} ${SRCS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
