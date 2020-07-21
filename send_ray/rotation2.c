/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:59:26 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:46:23 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_rot	rot_verif(t_vect rot, int angle)
{
	t_rot	r;
	double	c;
	double	s;

	c = cos(angle * (PI / 180));
	s = sin(angle * (PI / 180));
	r.x_rot.x = pow(rot.x, 2) * (1 - c) + c;
	r.x_rot.y = rot.x * rot.y * (1 - c) - rot.z * s;
	r.x_rot.z = rot.x * rot.z * (1 - c) + rot.y * s;
	r.y_rot.x = rot.x * rot.y * (1 - c) + rot.z * s;
	r.y_rot.y = pow(rot.y, 2) * (1 - c) + c;
	r.y_rot.z = rot.y * rot.z * (1 - c) - rot.x * s;
	r.z_rot.x = rot.x * rot.z * (1 - c) - rot.y * s;
	r.z_rot.y = rot.y * rot.z * (1 - c) + rot.x * s;
	r.z_rot.z = pow(rot.z, 2) * (1 - c) + c;
	return (r);
}

void	matrix_app(t_rot r, t_vect *ray)
{
	t_vect	tmp;

	tmp = *ray;
	ray->x = r.x_rot.x * tmp.x + r.x_rot.y * tmp.y + r.x_rot.z * tmp.z;
	ray->y = r.y_rot.x * tmp.x + r.y_rot.y * tmp.y + r.y_rot.z * tmp.z;
	ray->z = r.z_rot.x * tmp.x + r.z_rot.y * tmp.y + r.z_rot.z * tmp.z;
}

int		whichone(t_vect ori)
{
	int		nb;

	nb = 0;
	if (ori.x != 0)
		nb++;
	if (ori.y != 0)
		nb++;
	if (ori.z != 0)
		nb++;
	return (nb);
}

t_rot	double_x(t_vect ori)
{
	t_rot	r;
	int		angle;

	angle = acos(prodscal(ori, create_point(0, 0, ori.z)) / \
	(sqrt(norme2(ori)) * sqrt(norme2(create_point(0, 0, ori.z))))) \
	* (180 / PI);
	if ((ori.z < 0 && ori.y < 0) || (ori.z > 0 && ori.y < 0))
		angle = 360 - angle;
	if (ori.z > 0)
	{
		r = rot_verif(create_point(0, 1, 0), 180);
		r = matrixprod(r, rot_verif(create_point(1, 0, 0), angle));
	}
	else
		r = rot_verif(create_point(1, 0, 0), angle);
	return (r);
}

t_rot	matrixprod(t_rot r, t_rot re)
{
	t_rot	ra;

	ra.x_rot.x = r.x_rot.x * re.x_rot.x + r.x_rot.y \
	* re.y_rot.x + r.x_rot.z * re.z_rot.x;
	ra.x_rot.y = r.x_rot.x * re.x_rot.y + r.x_rot.y \
	* re.y_rot.y + r.x_rot.z * re.z_rot.y;
	ra.x_rot.z = r.x_rot.x * re.x_rot.z + r.x_rot.y \
	* re.y_rot.z + r.x_rot.z * re.z_rot.z;
	ra.y_rot.x = r.y_rot.x * re.x_rot.x + r.y_rot.y \
	* re.y_rot.x + r.y_rot.z * re.z_rot.x;
	ra.y_rot.y = r.y_rot.x * re.x_rot.y + r.y_rot.y \
	* re.y_rot.y + r.y_rot.z * re.z_rot.y;
	ra.y_rot.z = r.y_rot.x * re.x_rot.z + r.y_rot.y \
	* re.y_rot.z + r.y_rot.z * re.z_rot.z;
	ra.z_rot.x = r.z_rot.x * re.x_rot.x + r.z_rot.y \
	* re.y_rot.x + r.z_rot.z * re.z_rot.x;
	ra.z_rot.y = r.z_rot.x * re.x_rot.y + r.z_rot.y \
	* re.y_rot.y + r.z_rot.z * re.z_rot.y;
	ra.z_rot.z = r.z_rot.x * re.x_rot.z + r.z_rot.y \
	* re.y_rot.z + r.z_rot.z * re.z_rot.z;
	return (ra);
}
