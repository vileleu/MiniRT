/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:10 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/18 16:47:34 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutionpl(t_close *inter, t_pl *pl, t_ray ray, double t)
{
	if ((inter->solu == 0 && t > 0) || t < inter->solu)
	{
		inter->coord.x = pl->crdn.x;
		inter->coord.y = pl->crdn.y;
		inter->coord.z = pl->crdn.z;
		inter->col_form.x = pl->color.x;
		inter->col_form.y = pl->color.y;
		inter->col_form.z = pl->color.z;
		inter->solu = t;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = pl->orientation;
		if (norme2(ope('-', ope('+', inter->inter, inter->normale), ray.origin)) > norme2(ope('-', ope('-', inter->inter, inter->normale), ray.origin)))
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', ray.origin, inter->inter)));
		inter->form = PLAN;
	}
}

void	inter_pl(t_scene s, t_close *inter, t_ray ray)
{
	t_pl	*save;
	double	deno;
	double	nomi;
	double	t;

	save = s.pl;
	while (s.pl)
	{
		deno = prodscal(ray.direction, normalize(s.pl->orientation));
		if (deno)
		{
			nomi = prodscal(ope('-', s.pl->crdn, ray.origin), normalize(s.pl->orientation));
			t = nomi / deno;
			if (t > 0)
				solutionpl(inter, s.pl, ray, t);	
		}
		s.pl = s.pl->next;
	}
	s.pl = save;
}

void	iter_pl(t_scene s, t_close *inter, t_ray ray, t_vect verif)
{
	t_pl	*save;
	double	deno;
	double	nomi;
	double	t;

	save = s.pl;
	while (s.pl)
	{
		deno = prodscal(ray.direction, normalize(s.pl->orientation));
		if (deno && !samevect(s.pl->crdn, verif))
		{
			nomi = prodscal(ope('-', s.pl->crdn, ray.origin), normalize(s.pl->orientation));
			t = nomi / deno;
			if (t > 0)
				solutionpl(inter, s.pl, ray, t);	
		}
		s.pl = s.pl->next;
	}
	s.pl = save;
}