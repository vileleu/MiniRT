/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:48:22 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/01 18:28:16 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutionsp(t_close *inter, t_sp *sp, t_ray ray, double smallest)
{
	if (smallest == 0)
		return ;
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		add_color(&inter->col_form, sp->color);
		inter->solu = smallest;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = normalize(ope('-', inter->inter, sp->crdn));
		if (sqrt(norme2(ope('-', sp->crdn, ray.origin))) < sp->diameter / 2)
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', inter->inter, ray.origin)));
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