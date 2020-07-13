/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:02:55 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/13 18:13:05 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_rot	rot_double(t_vect ori, int angle)
{
	t_rot	r;

	if ((ori.x > 0 && ori.y == 0) || (ori.y < 0 && ori.x == 0))
		angle = 360 - angle;
	if (ori.y == 0)
		r = rot_verif(create_point(0, 1, 0), angle);
	else if (ori.x == 0)
		r = double_x(ori);
	else
	{
		if (ori.x < 0)
			r = rot_verif(create_point(0, 1, 0), 90);
		else
			r = rot_verif(create_point(0, 1, 0), 270);
		angle = acos(prodscal(ori, create_point(ori.x, 0, 0)) / (sqrt(norme2(ori)) * \
		sqrt(norme2(create_point(ori.x, 0, 0))))) * (180 / PI);
		if ((ori.x < 0 && ori.y > 0) || (ori.x > 0 && ori.y < 0))
			angle = 360 - angle;
		r = matrixprod(r, rot_verif(create_point(0, 0, 1), angle));
	}
	return (r);
}

t_rot	triple_bis(t_vect ori, int angle, t_rot r)
{
	if (ori.x < 0 && ori.z > 0)
	{
		if (ori.y > 0)
			angle = 360 - angle;
		r = matrixprod(r, rot_verif(create_point(1, 0, 0), angle));
		r = matrixprod(r, rot_verif(create_point(0, 0, 1), 360 - angle));
	}
	else
	{
		if (ori.y < 0)
			angle = 360 - angle;
		r = matrixprod(r, rot_verif(create_point(1, 0, 0), angle));
		r = matrixprod(r, rot_verif(create_point(0, 0, 1), 360 - angle));
	}
	return (r);
}

t_rot	rot_triple(t_vect ori)
{
	t_rot	r;
	int		angle;

	angle = acos(prodscal(create_point(ori.x, 0, ori.z), create_point(0, 0, -1)) / \
	(sqrt(norme2(create_point(ori.x, 0, ori.z))) * sqrt(norme2(create_point(0, 0, -1))))) * (180 / PI);
	r = rot_double(create_point(ori.x, 0, ori.z), angle);
	angle = (acos(prodscal(create_point(ori.x, 0, ori.z), ori) / \
	(sqrt(norme2(create_point(ori.x, 0, ori.z))) * sqrt(norme2(ori)))) * (180 / PI));
	if (ori.x < 0 && ori.z < 0)
	{
		if (ori.y < 0)
			angle = 360 - angle;
		r = matrixprod(r, rot_verif(create_point(1, 0, 0), angle));
		r = matrixprod(r, rot_verif(create_point(0, 0, 1), 360 - angle));
	}
	else if (ori.x > 0 && ori.z > 0)
	{
		if (ori.y > 0)
			angle = 360 - angle;
		r = matrixprod(r, rot_verif(create_point(1, 0, 0), angle));
		r = matrixprod(r, rot_verif(create_point(0, 0, 1), 360 - angle));
	}
	else
		r = triple_bis(ori, angle, r);
	return (r);
}

t_rot	rot_simple(t_vect ori, int angle)
{
	t_rot	r;

	if (ori.x > 0 || ori.y < 0)
		angle = 360 - angle;
	if (ori.x != 0 || ori.z != 0)
		r = rot_verif(create_point(0, 1, 0), angle);
	else
		r = rot_verif(create_point(1, 0, 0), angle);
	return (r);
}

t_rot	rot_apply(t_vect ori)
{
	t_rot	r;
	int		nb;
	int		angle;

	initialize_vect(&r.x_rot);
	initialize_vect(&r.y_rot);
	initialize_vect(&r.z_rot);
	nb = whichone(ori);
	angle = acos(prodscal(ori, create_point(0, 0, -1)) / (sqrt(norme2(ori)) * \
	sqrt(norme2(create_point(0, 0, -1))))) * (180 / PI);
	if (nb == 0)
	{
		r.x_rot.x = 1;
		r.y_rot.y = 1;
		r.z_rot.z = 1;
	}
	else if (nb == 1)
		r = rot_simple(ori, angle);
	else if (nb == 2)
		r = rot_double(ori, angle);
	else
		r = rot_triple(ori);
	return (r);
}