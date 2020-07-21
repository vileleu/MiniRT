/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:44:00 by sileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:23:32 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		whitespace(char *str, int *ptr)
{
	while (str[*ptr] == '\t' || str[*ptr] == ' ')
		(*ptr)++;
	if ((str[*ptr] < 48 || str[*ptr] > 57) && str[*ptr] != '-' \
	&& str[*ptr] != '\0')
		return (0);
	return (1);
}

int		parsing(char *str, t_scene *s)
{
	if (str[0] == '\0')
		return (1);
	else if (str[0] == 's' && str[1] == 'p')
		return (sphere(str, s, 2));
	else if (str[0] == 'p' && str[1] == 'l')
		return (plane(str, s, 2));
	else if (str[0] == 's' && str[1] == 'q')
		return (square(str, s, 2));
	else if (str[0] == 'c' && str[1] == 'y')
		return (cylindre(str, s, 2));
	else if (str[0] == 't' && str[1] == 'r')
		return (triangle(str, s, 2));
	else if (str[0] == 'R')
		return (resolution(str, s, 1));
	else if (str[0] == 'A')
		return (ambiante(str, s, 1));
	else if (str[0] == 'c')
		return (camera(str, s, 1));
	else if (str[0] == 'l')
		return (lumiere(str, s, 1));
	else
		return (0);
}

int		bef_pars(t_scene *s, char **av)
{
	char	*line;
	int		fd;
	int		verif;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((verif = parsing(line, s)) < 1)
		{
			free(line);
			return (error(verif, s));
		}
		free(line);
	}
	if ((verif = parsing(line, s)) < 1)
	{
		free(line);
		return (error(verif, s));
	}
	free(line);
	return (1);
}

void	initialize_vect(t_vect *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
}

void	init_scene(t_scene *s)
{
	s->verifr = 0;
	s->verifa = 0;
	s->cam = NULL;
	s->lum = NULL;
	s->sp = NULL;
	s->pl = NULL;
	s->sq = NULL;
	s->cy = NULL;
	s->tr = NULL;
	initialize_vect(&s->rot.x_rot);
	initialize_vect(&s->rot.y_rot);
	initialize_vect(&s->rot.z_rot);
}
