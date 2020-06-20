/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:35:45 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/18 14:36:43 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		samevect(t_vect a, t_vect b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return (1);
	return (0);
}

double	return_smallest(double x1, double x2)
{
	if (x1 == x2)
		return (x1);
	else if (x1 > 0 && x2 <= 0)
		return (x1);
	else if (x2 > 0 && x1 <= 0)
		return (x2);
	else if (x1 < x2)
		return (x1);
	else if (x2 < x1)
		return (x2);
	else
		return (0);
}

void	initialize_vect(t_vect *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
}

void	initialize_color(t_color *a)
{
	a->x = 0;
	a->y = 0;
	a->z = 0;
}

void	initialize_inter(t_close *inter)
{
	inter->form = 0;
	inter->solu = 0;
	inter->dist = 0;
	initialize_vect(&inter->cam);
	initialize_vect(&inter->coord);
	initialize_vect(&inter->normale);
	initialize_vect(&inter->inter);
	initialize_color(&inter->col_form);
	initialize_color(&inter->col_final);
}