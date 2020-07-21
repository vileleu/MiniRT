/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:45:03 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:49:09 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutiontr(t_close *inter, t_tr *tr, t_ray ray, double smallest)
{
	if (smallest == 0)
		return ;
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		add_color(&inter->col_form, tr->color);
		inter->solu = smallest;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = normalize(croisement(ope('-', tr->crdn2, tr->crdn1), \
		ope('-', tr->crdn3, tr->crdn1)));
		if (norme2(ope('-', ope('+', inter->inter, inter->normale), \
		ray.origin)) > norme2(ope('-', ope('-', inter->inter, inter->normale), \
		ray.origin)))
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', inter->inter, ray.origin)));
	}
}

void	inter_trbis(t_scene s, t_close *inter, t_ray ray)
{
	t_vect	p[2];
	t_vect	vectr[3];
	double	verif[4];
	double	t;

	p[0] = ope('-', s.tr->crdn2, s.tr->crdn1);
	p[1] = ope('-', s.tr->crdn3, s.tr->crdn1);
	vectr[0] = croisement(ray.direction, p[1]);
	verif[0] = prodscal(p[0], vectr[0]);
	if (verif[0] > -E && verif[0] < E)
		return ;
	verif[1] = 1.0 / verif[0];
	vectr[1] = ope('-', ray.origin, s.tr->crdn1);
	verif[2] = verif[1] * prodscal(vectr[1], vectr[0]);
	if (verif[2] < 0.0 || verif[2] > 1.0)
		return ;
	vectr[2] = croisement(vectr[1], p[0]);
	verif[3] = verif[1] * prodscal(ray.direction, vectr[2]);
	if (verif[3] < 0.0 || verif[2] + verif[3] > 1.0)
		return ;
	t = verif[1] * prodscal(p[1], vectr[2]);
	if (t > E)
		solutiontr(inter, s.tr, ray, t);
}

void	inter_tr(t_scene s, t_close *inter, t_ray ray)
{
	t_tr	*save;

	save = s.tr;
	while (s.tr != NULL)
	{
		inter_trbis(s, inter, ray);
		s.tr = s.tr->next;
	}
	s.tr = save;
}
