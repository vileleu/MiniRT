/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:14:51 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:27:40 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	solutionsq(t_close *inter, t_sq *sq, t_ray ray, double t)
{
	if (t == 0)
		return ;
	if ((inter->solu == 0 && t > 0) || t < inter->solu)
	{
		add_color(&inter->col_form, sq->color);
		inter->solu = t;
		inter->inter = ope('+', ray.origin, multi(ray.direction, inter->solu));
		inter->normale = sq->orientation;
		if (prodscal(ray.direction, inter->normale) >= 0)
			inter->normale = multi(inter->normale, -1);
		inter->dist = sqrt(norme2(ope('-', inter->inter, ray.origin)));
	}
}

float	inter_plane(t_ray ray, t_sq *sq)
{
	double	a;
	double	b;
	double	t;
	t_vect	tmp;

	tmp = ope('-', ray.origin, sq->crdn);
	a = prodscal(tmp, sq->orientation);
	b = prodscal(ray.direction, sq->orientation);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	return (t);
}

void	inter_sqbis(t_scene s, t_close *inter, t_ray ray)
{
	double	t;
	double	a;
	double	b;
	t_vect	p;
	t_vect	data;

	if (!(t = inter_plane(ray, s.sq)))
		return ;
	data = multi(ray.direction, t);
	p = ope('+', ray.origin, data);
	data = ope('-', p, s.sq->a);
	a = prodscal(data, ope('-', s.sq->b, s.sq->a)) / prodscal(ope('-', \
	s.sq->b, s.sq->a), ope('-', s.sq->b, s.sq->a));
	b = prodscal(data, ope('-', s.sq->c, s.sq->a)) / prodscal(ope('-', \
	s.sq->c, s.sq->a), ope('-', s.sq->c, s.sq->a));
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1)
		solutionsq(inter, s.sq, ray, t);
}

void	inter_sq(t_scene s, t_close *inter, t_ray ray)
{
	t_sq	*save;

	save = s.sq;
	while (s.sq != NULL)
	{
		inter_sqbis(s, inter, ray);
		s.sq = s.sq->next;
	}
	s.sq = save;
}
