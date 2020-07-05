/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:04:42 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/26 19:19:22 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutioncy(t_close *inter, t_tr *tr, t_ray ray, double smallest)
{
	if (smallest == 0)
		return ;
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		add_point(&inter->coord, tr->crdn1);
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
		vect[0] = ope('-', ope('+', s.cy->crdn, ope('*', s.cy->orientation, s.cy->height)), s.cy->crdn);
		vect[1] = ope('-', ray.origin, s.cy->crdn);
		verif[0] = prodscal(vect[0], vect[0]);
		verif[1] = prodscal(vect[0], ray.direction);
		verif[2] = prodscal(vect[0], vect[1]);
		verif[5] = verif[0] - pow(verif[1], 2);
		verif[6] = verif[0] * prodscal(vect[1], ray.direction) - (verif[2] * verif[1]);
		verif[7] = verif[0] * prodscal(vect[1], vect[1]) - pow(verif[2], 2) - ((pow(s.cy->diameter, 2)) * verif[0]);
		verif[3] = pow(verif[6], 2) - (verif[5] * verif[7]);
		if (verif[3] < 0)
			return ;
		verif[3] = sqrt(verif[3]);
		verif[8] = (-verif[6] - verif[3]) / verif[5];
		verif[4] = verif[2] + verif[8] * verif[1];
		if (verif[4] > 0 && verif[4] < verif[0] && verif[8] > 0)
			return (get_inter_norminette(verif, ray.origin, ray.direction, cyl));
		verif[8] = (-verif[6] + verif[3]) / verif[5];
		verif[4] = verif[2] + verif[8] * verif[1];
		return (get_inter_norminette1(verif, ray.origin, ray.direction, cyl));
	}
	s.cy = save;
}