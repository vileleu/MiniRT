/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:55:01 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/20 15:31:55 by vileleu          ###   ########.fr       */
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
	ray.direction = normalize(ray.direction);
	return (ray);
}

/*t_ray	newray_enlight(t_close *inter, t_lum *light)
{
	t_ray	ray;

	ray.origin.x = inter->inter.x;
	ray.origin.y = inter->inter.y;
	ray.origin.z = inter->inter.z;
	ray.direction = ope('-', light->crdn, ray.origin);
	ray.direction = normalize(ray.direction);
	return (ray);
}*/

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