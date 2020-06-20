/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:50:07 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/20 19:14:59 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_close		enlight_obj(t_scene s, t_close *inter, t_ray ray_light)
{
	t_close	preuve;
	t_close	prouve;

	initialize_inter(&preuve);
	initialize_inter(&prouve);
	if (inter->form == SPHERE)
		iter_sp(s, &preuve, ray_light, inter->coord);
	else
		inter_sp(s, &preuve, ray_light);
	if (inter->form == PLAN)
		iter_pl(s, &prouve, ray_light, inter->coord);
	else
		inter_pl(s, &prouve, ray_light);
	if (return_smallest(preuve.dist, prouve.dist) == prouve.dist)
		preuve = prouve;
	return (preuve);
}

int			enlight(t_scene s, t_close *inter, t_lum *light)
{
	t_ray	ray_light;
	t_close	preuve;
	double	dist_l;
	double	dist_inter;

	ray_light = newray_enlight(inter, light);
	preuve = enlight_obj(s, inter, ray_light);
	dist_l = sqrt(norme2(ope('-', light->crdn, inter->inter)));
	dist_inter = sqrt(norme2(ope('-', preuve.inter, inter->inter)));
	if (preuve.dist > E && preuve.dist + E < dist_l && dist_inter + E < preuve.dist + dist_l)
		return (0);
	return (1);
}
