/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:24:32 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/20 18:44:25 by vileleu          ###   ########.fr       */
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
	/*inter_sq();
	inter_tr();
	inter_cy();*/
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
			i = prodscal(normalize(ope('-', s.lum->crdn, inter->inter)), inter->normale) / norme2(ope('-', s.lum->crdn, inter->inter));
			if (i < 0)
				i = 0;
			final_light(s.lum, inter, i);
		}
		s.lum = s.lum->next;
	}
	s.lum = light;
}

void	checkpixel(t_scene s, t_libx *d, t_pixel *pix)
{
	t_close	inter;
	
	pix->col = 0;
	pix->i = 0;
	while (pix->i < s.res_y)
	{
		pix->j = 0;
		while (pix->j < s.res_x)
		{
			initialize_inter(&inter);
			inter.cam = s.cam->crdn;
			if (inter_forms(s, pix, &inter))
				inter_light(s, &inter);
			d->data[(pix->col)++] = inter.col_final.x;
			d->data[(pix->col)++] = inter.col_final.y;
			d->data[(pix->col)++] = inter.col_final.z;
			d->data[(pix->col)++] = 0;
			(pix->j)++;
		}
		(pix->i)++;
	}
	mlx_put_image_to_window(d->init, d->win, d->img, 0, 0);
}

int		deal_key(int key, void *param)
{
	t_libx	*d;
	t_pixel	pix;

	d = (t_libx*)param;
	if (key == 53)
	{
		mlx_destroy_image(d->init, d->img);
		mlx_destroy_window(d->init, d->win);
		exit(0);
	}
	else if (key == 49)
	{
		mlx_destroy_image(d->init, d->img);
		if (d->sah.cam->next == NULL)
			d->sah.cam = d->save_cam;
		else
			d->sah.cam = d->sah.cam->next;
		d->img = mlx_new_image(d->init, d->sah.res_x, d->sah.res_y);
		d->data = mlx_get_data_addr(d->img, &d->bits, &d->size, &d->end);
		checkpixel(d->sah, d, &pix);
	}
	return (0);
}

int		mlx_cam(t_scene s)
{
	t_libx	d;
	t_pixel	pix;

	d.prems = 0;
	d.sah = s;
	d.save_cam = s.cam;
	pix.i = 0;
	pix.j = 0;
	pix.col = 0;
	d.init = mlx_init();
	d.win = mlx_new_window(d.init, s.res_x, s.res_y, "Bienvenue!");
	d.img = mlx_new_image(d.init, s.res_x, s.res_y);
	d.data = mlx_get_data_addr(d.img, &d.bits, &d.size, &d.end);
	checkpixel(s, &d, &pix);
	mlx_key_hook(d.win, deal_key, &d);
	mlx_loop(d.init);
	return (1);
}