/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:04:42 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 18:59:52 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutioncy(t_close *inter, t_cy *cy, t_ray ray, double smallest)
{
	t_vect	caps[3];
	double	rayon;

	if (smallest == 0)
		return ;
	if ((inter->solu == 0 && smallest > 0) || smallest < inter->solu)
	{
		add_color(&inter->col_form, cy->color);
		inter->solu = smallest;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		caps[0] = ope('+', cy->crdn, multi(cy->orientation, cy->height / 2));
		caps[1] = ope('-', inter->inter, caps[0]);
		rayon = prodscal(caps[1], cy->orientation);
		caps[2] = ope('-', caps[1], multi(cy->orientation, rayon));
		inter->normale = normalize(divi(caps[2], cy->diameter));
		if (sqrt(norme2(ope('-', ope('+', inter->inter, inter->normale), \
		ray.origin))) > sqrt(norme2(ope('-', ope('-', inter->inter, \
		inter->normale), ray.origin))))
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', inter->inter, ray.origin)));
	}
}

void	inter_cybis(t_scene s, t_close *inter, t_ray ray)
{
	t_vect	v[2];
	double	cal[9];

	v[0] = ope('-', ope('+', s.cy->crdn, multi(s.cy->orientation, \
	s.cy->height)), s.cy->crdn);
	v[1] = ope('-', ray.origin, s.cy->crdn);
	cal[6] = prodscal(v[0], v[0]);
	cal[7] = prodscal(v[0], ray.direction);
	cal[8] = prodscal(v[0], v[1]);
	cal[0] = cal[6] - pow(cal[7], 2);
	cal[1] = cal[6] * prodscal(v[1], ray.direction) - cal[8] * cal[7];
	cal[2] = cal[6] * prodscal(v[1], v[1]) - cal[8] * cal[8] - \
	pow(s.cy->diameter, 2) * cal[6];
	cal[3] = cal[1] * cal[1] - cal[0] * cal[2];
	if (cal[3] < 0)
		return ;
	cal[3] = sqrt(cal[3]);
	cal[4] = (-1 * cal[1] - cal[3]) / cal[0];
	cal[5] = cal[8] + cal[4] * cal[7];
	if (cal[5] > 0 && cal[5] < cal[6] && cal[4] > E)
		solutioncy(inter, s.cy, ray, cal[4]);
	cal[4] = (-1 * cal[1] + cal[3]) / cal[0];
	cal[5] = cal[8] + cal[4] * cal[7];
	if (cal[5] > 0 && cal[5] < cal[6] && cal[4] > E)
		solutioncy(inter, s.cy, ray, cal[4]);
}

void	inter_cy(t_scene s, t_close *inter, t_ray ray)
{
	t_cy	*save;

	save = s.cy;
	while (s.cy != NULL)
	{
		inter_cybis(s, inter, ray);
		s.cy = s.cy->next;
	}
	s.cy = save;
}
