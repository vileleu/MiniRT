/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:35:45 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 18:09:39 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

double	return_smallest(double x1, double x2)
{
	if (x1 <= 0 && x2 <= 0)
		return (0);
	else if (x1 > 0 && x2 <= 0)
		return (x1);
	else if (x2 > 0 && x1 <= 0)
		return (x2);
	else if (x1 < x2)
		return (x1);
	else if (x2 < x1)
		return (x2);
	else if (x1 == x2)
		return (x1);
	else
		return (0);
}

void	initialize_color(t_color *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
}

t_vect	create_point(double a, double b, double c)
{
	t_vect	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_vect	divi(t_vect a, double b)
{
	t_vect	new;

	new.x = a.x / b;
	new.y = a.y / b;
	new.z = a.z / b;
	return (new);
}

void	initialize_inter(t_close *inter)
{
	inter->solu = 0;
	inter->dist = 0;
	initialize_vect(&inter->normale);
	initialize_vect(&inter->inter);
	initialize_color(&inter->col_form);
	initialize_color(&inter->col_final);
}
