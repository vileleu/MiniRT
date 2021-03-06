/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:24:32 by vileleu           #+#    #+#             */
/*   Updated: 2020/09/13 15:25:05 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		inter_forms(t_scene s, t_pixel *pix, t_close *inter)
{
	t_close	second;
	t_ray	ray;

	initialize_inter(&second);
	ray = newray(s, *pix);
	inter_sp(s, inter, ray);
	inter_pl(s, &second, ray);
	if (return_smallest(inter->dist, second.dist) == second.dist)
		*inter = second;
	initialize_inter(&second);
	inter_tr(s, &second, ray);
	if (return_smallest(inter->dist, second.dist) == second.dist)
		*inter = second;
	initialize_inter(&second);
	inter_sq(s, &second, ray);
	if (return_smallest(inter->dist, second.dist) == second.dist)
		*inter = second;
	initialize_inter(&second);
	inter_cy(s, &second, ray);
	if (return_smallest(inter->dist, second.dist) == second.dist)
		*inter = second;
	if (inter->dist)
		return (1);
	return (0);
}

void	inter_light(t_scene s, t_close *inter)
{
	t_lum	*light;
	double	i;

	light = s.lum;
	amb_light(s, inter);
	while (s.lum != NULL)
	{
		if (enlight(s, inter, s.lum))
		{
			i = prodscal(normalize(ope('-', s.lum->crdn, inter->inter)), \
			inter->normale) / norme2(ope('-', s.lum->crdn, inter->inter));
			if (i < 0)
				i = 0;
			final_light(s.lum, inter, i);
		}
		s.lum = s.lum->next;
	}
	s.lum = light;
}

void	checkpixel(t_scene s, char *data, t_pixel *pix)
{
	t_close	inter;

	pix->col = 0;
	pix->i = 0;
	s.rot = rot_apply(s.cam->orientation);
	while (pix->i < s.res_y)
	{
		pix->j = 0;
		while (pix->j < s.res_x)
		{
			initialize_inter(&inter);
			if (inter_forms(s, pix, &inter))
				inter_light(s, &inter);
			data[(pix->col)++] = inter.col_final.x;
			data[(pix->col)++] = inter.col_final.y;
			data[(pix->col)++] = inter.col_final.z;
			data[(pix->col)++] = 0;
			(pix->j)++;
		}
		(pix->i)++;
	}
}

int		mlx_cam(t_scene s)
{
	t_libx	d;
	t_pixel	pix;

	d.sah = s;
	pix.i = 0;
	pix.j = 0;
	pix.col = 0;
	d.init = mlx_init();
	d.win = mlx_new_window(d.init, s.res_x, s.res_y, "Bienvenue!");
	if (!(create_image(s, &d, &pix)))
		exit(0);
	mlx_put_image_to_window(d.init, d.win, d.list->img, 0, 0);
	mlx_hook(d.win, 33, 1L << 17, mouse, &d);
	mlx_key_hook(d.win, deal_key, &d);
	mlx_loop(d.init);
	return (1);
}
