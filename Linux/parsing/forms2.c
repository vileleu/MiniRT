/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:04:31 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:22:24 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		cylindre2(char *str, int *ptr, t_cy *o)
{
	if (!(whitespace(str, ptr)))
		return (0);
	if (!(ft_atoi3(str, ptr, &(o->color))))
		return (0);
	if (!(whitespace(str, ptr)))
		return (0);
	o->diameter /= 2;
	return (1);
}

int		triangle2(char *str, int *ptr, t_tr *o)
{
	if (!(whitespace(str, ptr)))
		return (0);
	if (!(ft_atoi3(str, ptr, &(o->color))))
		return (0);
	if (!(whitespace(str, ptr)))
		return (0);
	return (1);
}

void	square2(t_sq *o)
{
	t_vect	v[4];
	t_rot	r;

	v[0] = create_point(o->height / 2, o->height / 2, 0);
	v[1] = create_point(o->height / 2 * -1, o->height / 2, 0);
	v[2] = create_point(o->height / 2, o->height / 2 * -1, 0);
	v[3] = create_point(o->height / 2 * -1, o->height / 2 * -1, 0);
	r = rot_apply(o->orientation);
	matrix_app(r, &v[0]);
	matrix_app(r, &v[1]);
	matrix_app(r, &v[2]);
	matrix_app(r, &v[3]);
	o->a = ope('+', v[0], o->crdn);
	o->b = ope('+', v[1], o->crdn);
	o->c = ope('+', v[2], o->crdn);
	o->d = ope('+', v[3], o->crdn);
}
