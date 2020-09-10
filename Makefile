SRCS		= parsing/ft_add_objects.c parsing/ft_add_forms.c main/main.c parsing/ft_ato.c \
			parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parsing.c \
			parsing/objects.c parsing/forms.c parsing/forms2.c parsing/error.c \
			send_ray/utils_calcul.c send_ray/sphere.c send_ray/utils_rays.c \
			send_ray/intersection.c send_ray/functions_light.c send_ray/utils_others.c \
			send_ray/shadows.c send_ray/plane.c send_ray/triangle.c send_ray/rotation.c \
			send_ray/image.c send_ray/carre.c send_ray/rotation2.c send_ray/events.c \
			send_ray/cylindre.c send_ray/save_bmp.c
			
OBJS		= ${SRCS:.c=.o}

NAME		= Minirt

INCS		= -I srcs/header.h

lIBX		= 

CC			= gcc -Wall -Wextra -Werror

RM			= rm -rf

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
	${MAKE} -C minilibx_opengl_20191021
	LIBX += -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME),Linux)
	${MAKE} -C minilibx-linux
	LIBX += -L minilibx-linux -lmlx -lm -lXext -lX11 -lpthread -lbsd

endif

.c.o:		${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${INCS} ${LIBX}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
