/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:06:34 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:02:28 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_vect	ope(char c, t_vect a, t_vect b)
{
	t_vect	new;

	if (c == '+')
	{
		new.x = a.x + b.x;
		new.y = a.y + b.y;
		new.z = a.z + b.z;
	}
	else if (c == '-')
	{
		new.x = a.x - b.x;
		new.y = a.y - b.y;
		new.z = a.z - b.z;
	}
	else
	{
		new.x = a.x * b.x;
		new.y = a.y * b.y;
		new.z = a.z * b.z;
	}
	return (new);
}

double	prodscal(t_vect a, t_vect b)
{
	double	new;

	new = a.x * b.x + a.y * b.y + a.z * b.z;
	return (new);
}

double	norme2(t_vect a)
{
	double	new;

	new = a.x * a.x + a.y * a.y + a.z * a.z;
	return (new);
}

t_vect	normalize(t_vect v)
{
	double	norm;

	norm = sqrt(norme2(v));
	v.x /= norm;
	v.y /= norm;
	v.z /= norm;
	return (v);
}

t_vect	multi(t_vect a, double b)
{
	t_vect	new;

	new.x = a.x * b;
	new.y = a.y * b;
	new.z = a.z * b;
	return (new);
}
