/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:48:22 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/19 14:28:36 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutionsp(t_close *inter, t_sp *sp, t_ray ray, double smallest)
{
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		inter->coord.x = sp->crdn.x;
		inter->coord.y = sp->crdn.y;
		inter->coord.z = sp->crdn.z;
		inter->col_form.x = sp->color.x;
		inter->col_form.y = sp->color.y;
		inter->col_form.z = sp->color.z;
		inter->solu = smallest;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = normalize(ope('-', inter->inter, inter->coord));
		if (sqrt(norme2(ope('-', sp->crdn, ray.origin))) < sp->diameter / 2)
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', ray.origin, inter->inter)));
		inter->form = SPHERE;
	}
}

void	inter_sp(t_scene s, t_close *inter, t_ray ray)
{
	t_sp	*save;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	save = s.sp;
	while (s.sp != NULL)
	{
		b = 2 * prodscal(ray.direction, ope('-', ray.origin, s.sp->crdn));
		c = norme2(ope('-', ray.origin, s.sp->crdn)) - pow(s.sp->diameter / 2, 2);
		delta = b * b - 4 * c;
		if (delta >= 0)
		{
			t1 = (-b - sqrt(delta)) / 2;
			t2 = (-b + sqrt(delta)) / 2;
			solutionsp(inter, s.sp, ray, return_smallest(t1, t2));
		}
		s.sp = s.sp->next;
	}
	s.sp = save;
}

void	iter_sp(t_scene s, t_close *inter, t_ray ray, t_vect verif)
{
	t_sp	*save;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	save = s.sp;
	while (s.sp != NULL)
	{
		b = 2 * prodscal(ray.direction, ope('-', ray.origin, s.sp->crdn));
		c = norme2(ope('-', ray.origin, s.sp->crdn)) - pow(s.sp->diameter / 2, 2);
		delta = b * b - 4 * c;
		if (delta >= 0 && !samevect(s.sp->crdn, verif))
		{
			t1 = (-b - sqrt(delta)) / 2;
			t2 = (-b + sqrt(delta)) / 2;
			solutionsp(inter, s.sp, ray, return_smallest(t1, t2));
		}
		s.sp = s.sp->next;
	}
	s.sp = save;
}