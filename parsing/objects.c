/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:41:14 by vileleu           #+#    #+#             */
/*   Updated: 2020/03/09 17:13:44 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		resolution(char *str, t_scene *s, int i)
{
	if (s->verifr == 1)
		return (-2);
	if (!(whitespace(str, &i)))
		return (0);
	s->res_x = ft_atoi(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	s->res_y = ft_atoi(str, &i);
	s->verifr = 1;
	return (1);
}

int		ambiante(char *str, t_scene *s, int i)
{
	if (s->verifa == 1)
		return (-2);
	if (!(whitespace(str, &i)))
		return (0);
	s->lum_amb = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atoi3(str, &i, &(s->color_lum_amb))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	s->verifa = 1;
	return (1);
}

int		camera(char *str, t_scene *s, int i)
{
	t_cam	*o;

	if (!(o = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	o->next = NULL;
	ft_add_cam(&(s->cam), o);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->orientation))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	o->fov = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	return (1);
}

int		lumiere(char *str, t_scene *s, int i)
{
	t_lum	*o;
	
	if (!(o = (t_lum *)malloc(sizeof(t_lum))))
		return (-1);
	o->next = NULL;
	ft_add_lum(&(s->lum), o);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	o->ratio = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atoi3(str, &i, &(o->color))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	return (1);
}
