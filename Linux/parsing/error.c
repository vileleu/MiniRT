/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:25:35 by vileleu           #+#    #+#             */
/*   Updated: 2020/09/12 15:36:33 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

void	free_scene2(t_scene tmp, t_scene *s)
{
	while (s->pl != NULL)
	{
		tmp.pl = s->pl;
		s->pl = s->pl->next;
		free(tmp.pl);
	}
	while (s->sq != NULL)
	{
		tmp.sq = s->sq;
		s->sq = s->sq->next;
		free(tmp.sq);
	}
	while (s->cy != NULL)
	{
		tmp.cy = s->cy;
		s->cy = s->cy->next;
		free(tmp.cy);
	}
	while (s->tr != NULL)
	{
		tmp.tr = s->tr;
		s->tr = s->tr->next;
		free(tmp.tr);
	}
}

void	free_scene(t_scene *s)
{
	t_scene	tmp;

	while (s->cam != NULL)
	{
		tmp.cam = s->cam;
		s->cam = s->cam->next;
		free(tmp.cam);
	}
	while (s->lum != NULL)
	{
		tmp.lum = s->lum;
		s->lum = s->lum->next;
		free(tmp.lum);
	}
	while (s->sp != NULL)
	{
		tmp.sp = s->sp;
		s->sp = s->sp->next;
		free(tmp.sp);
	}
	free_scene2(tmp, s);
}

int		error(int verif, t_scene *s)
{
	free_scene(s);
	printf("Error\n");
	if (verif == 0)
		printf("Bad character in file .rt\n");
	else if (verif == -1)
		printf("Malloc problem\n");
	else if (verif == 10)
		printf("Too many camera for argument '-save'\n");
	else if (verif == 11)
		printf("Error during creation of bmp file\n");
	else if (verif == 12)
		printf("Need camera, resolution and ambient light to \
launch the program\n");
	else
		printf("There is only one ambient light and one resolution\n");
	return (0);
}
