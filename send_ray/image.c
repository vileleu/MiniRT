/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:18:30 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/20 18:10:17 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

t_img	*create_img_list()
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img = (void *)0;
	img->data = NULL;
	img->bits = 0;
	img->size = 0;
	img->end = 0;
	img->next = NULL;
	return (img);
}

void	create_img(t_scene s, t_libx *d, t_pixel pix)
{
	t_cam	*cam;

	cam = s.cam;
	while (s.cam != NULL)
	{
		d->l_img = create_img_list();
		d->l_img->img = mlx_new_image(d->init, s.res_x, s.res_y);
		d->l_img->data = mlx_get_data_addr(d->l_img->img, &d->l_img->bits, &d->l_img->size, &d->l_img->end);
		checkpixel(s, d, &pix);
		if (d->prems == 0)
		{
			d->save_img = d->l_img;
			d->prems = 1;
		}
		d->l_img = d->l_img->next;
		s.cam = s.cam->next;
	}
	d->l_img = d->save_img;
	s.cam = cam;
}

void	delete_img(t_libx *d)
{
	t_img	*temp;

	while (d->l_img != NULL)
	{	
		temp = d->l_img;
		mlx_destroy_image(d->init, d->l_img->img);
		d->l_img = d->l_img->next;
		free(temp);
	}
}