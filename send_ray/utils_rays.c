/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:55:01 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/05 18:37:27 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_ray	newray(t_scene s, t_pixel pix)
{
	t_ray	ray;

	ray.origin.x = s.cam->crdn.x;
	ray.origin.y = s.cam->crdn.y;
	ray.origin.z = s.cam->crdn.z;
	ray.direction.x = pix.j - s.res_x / 2;
	ray.direction.y = pix.i - s.res_y / 2;
	ray.direction.z = -s.res_x / (2 * tan(s.cam->fov * PI / 180 / 2));
	if (s.cam->orientation.x != 0 || s.cam->orientation.y != 0 || s.cam->orientation.z != 0)
		rot_apply(&ray.direction, s.cam->orientation);
	ray.direction = normalize(ray.direction);
	return (ray);
}

t_ray	newray_enlight(t_close *inter, t_lum *light)
{
	t_ray	ray;

	ray.origin.x = light->crdn.x;
	ray.origin.y = light->crdn.y;
	ray.origin.z = light->crdn.z;
	ray.direction = ope('-', inter->inter, ray.origin);
	ray.direction = normalize(ray.direction);
	return (ray);
}

t_vect	create_point(double a, double b, double c)
{
	t_vect	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_vect	croisement(t_vect a, t_vect b)
{
	t_vect	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

void	add_color(t_color *a, t_color b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
}