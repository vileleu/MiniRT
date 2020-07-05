/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:02:55 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/05 18:27:12 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

/*t_rot	multimatrix(t_cam *cam)
{
	t_rot	r;

	r.z_rot = ori;
	if (ori.y == 1)
		r.x_rot = create_point(1, 0, 0);
	else if (ori.y == -1)
		r.x_rot = create_point(-1, 0, 0);
	else
		r.x_rot = croisement(create_point(0, 1, 0), r.z_rot);
	r.y_rot = croisement(r.z_rot, r.x_rot);
	return (r);
}*/

t_rot	rot_verif(t_vect ori)
{
	t_rot	r;

	t_vect	v;
	double	c;
	double	s;
	double	re;

	v = croisement(ori, create_point(0, 1, 0));
	c = prodscal(create_point(0, 1, 0), ori);
	s = norme2(v);
	re = ((1 - c) / s);
	r.x_rot.x = -re * (pow(v.y, 2) + pow(v.z, 2)) + 1;
	r.x_rot.y = re * v.x * v.y - v.z;
	r.x_rot.z = re * v.x * v.z + v.y;
	r.y_rot.x = re * v.x * v.y + v.z;
	r.y_rot.y = -re * (pow(v.x, 2) + pow(v.z, 2)) + 1;
	r.y_rot.z = re * v.y * v.x - v.x;
	r.z_rot.x = re * v.x * v.z - v.y;
	r.z_rot.y = re * v.y * v.z - v.x;
	r.z_rot.z = -re * (pow(v.x, 2) + pow(v.y, 2)) + 1;
	return (r);
}

void	rot_apply(t_vect *ray, t_vect ori)
{
	t_rot	r;

	if (ori.x == 0 && ori.y == 0 && ori.z == -1)
		return ;
	else if (ori.x == 0 && ori.y == 0 && ori.z == 1)
		ray->z = ray->z * -1;
	else
	{
		r = rot_verif(ori);
		ray->x = r.x_rot.x * ray->x + r.x_rot.y * ray->y + r.x_rot.z * ray->z;
		ray->y = r.y_rot.x * ray->x + r.y_rot.y * ray->y + r.y_rot.z * ray->z;
		ray->z = r.z_rot.x * ray->x + r.z_rot.y * ray->y + r.z_rot.z * ray->z;
	}
}