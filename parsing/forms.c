/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:38:40 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:22:36 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		sphere(char *str, t_scene *s, int i)
{
	t_sp	*o;

	if (!(o = (t_sp *)malloc(sizeof(t_sp))))
		return (-1);
	o->next = NULL;
	ft_add_sp(&(s->sp), o);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	o->diameter = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atoi3(str, &i, &(o->color))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	return (1);
}

int		plane(char *str, t_scene *s, int i)
{
	t_pl	*o;

	if (!(o = (t_pl *)malloc(sizeof(t_pl))))
		return (-1);
	o->next = NULL;
	ft_add_pl(&(s->pl), o);
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
	if (!(ft_atoi3(str, &i, &(o->color))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	return (1);
}

int		square(char *str, t_scene *s, int i)
{
	t_sq	*o;

	if (!(o = (t_sq *)malloc(sizeof(t_sq))))
		return (-1);
	o->next = NULL;
	ft_add_sq(&(s->sq), o);
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
	o->height = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atoi3(str, &i, &(o->color))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	square2(o);
	return (1);
}

int		cylindre(char *str, t_scene *s, int i)
{
	t_cy	*o;

	if (!(o = (t_cy *)malloc(sizeof(t_cy))))
		return (-1);
	o->next = NULL;
	ft_add_cy(&(s->cy), o);
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
	o->diameter = ft_atof(str, &i);
	if (!(whitespace(str, &i)))
		return (0);
	o->height = ft_atof(str, &i);
	if (!(cylindre2(str, &i, o)))
		return (0);
	return (1);
}

int		triangle(char *str, t_scene *s, int i)
{
	t_tr	*o;

	if (!(o = (t_tr *)malloc(sizeof(t_tr))))
		return (-1);
	o->next = NULL;
	ft_add_tr(&(s->tr), o);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn1))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn2))))
		return (0);
	if (!(whitespace(str, &i)))
		return (0);
	if (!(ft_atof3p(str, &i, &(o->crdn3))))
		return (0);
	if (!(triangle2(str, &i, o)))
		return (0);
	return (1);
}
