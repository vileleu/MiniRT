/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:04:42 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/13 18:58:41 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutioncy(t_close *inter, t_tr *tr, t_ray ray, double smallest)
{
	if (smallest == 0)
		return ;
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		add_color(&inter->col_form, tr->color);
		inter->solu = smallest;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = normalize(croisement(ope('-', tr->crdn2, tr->crdn1), ope('-', tr->crdn3, tr->crdn1)));
		if (norme2(ope('-', ope('+', inter->inter, inter->normale), ray.origin)) > norme2(ope('-', ope('-', inter->inter, inter->normale), ray.origin)))
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', inter->inter, ray.origin)));
	}
}

void	inter_cy(t_scene s, t_close *inter, t_ray ray)
{
	t_vect	vect[2];
	double	verif[9];
	t_cy	*save;

	save = s.cy;
	while (s.cy != NULL)
	{
		
	}
	s.cy = save;
}