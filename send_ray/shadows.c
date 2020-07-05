/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:50:07 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/05 18:35:43 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_close		enlight_obj(t_scene s, t_ray ray_light)
{
	t_close	preuve;
	t_close	prouve;

	initialize_inter(&preuve);
	initialize_inter(&prouve);
	inter_sp(s, &preuve, ray_light);
	inter_pl(s, &prouve, ray_light);
	if (return_smallest(preuve.dist, prouve.dist) == prouve.dist)
		preuve = prouve;
	initialize_inter(&prouve);
	inter_tr(s, &prouve, ray_light);
	if (return_smallest(preuve.dist, prouve.dist) == prouve.dist)
		preuve = prouve;
	initialize_inter(&prouve);
	inter_sq(s, &prouve, ray_light);
	if (return_smallest(preuve.dist, prouve.dist) == prouve.dist)
		preuve = prouve;
	return (preuve);
}

int			enlight(t_scene s, t_close *inter, t_lum *light)
{
	t_ray	ray_light;
	t_close	preuve;
	double	d_l;

	ray_light = newray_enlight(inter, light);
	initialize_inter(&preuve);
	d_l = sqrt(norme2(ope('-', inter->inter, light->crdn)));
	preuve = enlight_obj(s, ray_light);
	if (preuve.dist > E && preuve.dist + E < d_l)
		return (0);
	return (1);
}
