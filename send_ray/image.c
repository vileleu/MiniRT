/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:45:54 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:28:36 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	free_image(t_libx *d)
{
	t_image	*tmp;

	while (d->list)
	{
		tmp = d->list;
		d->list = d->list->next;
		mlx_destroy_image(d->init, tmp->img);
		free(tmp);
	}
}

void	ft_add_img(t_image **alst, t_image *new)
{
	new->next = *alst;
	*alst = new;
}

int		create_image(t_scene s, t_libx *d, t_pixel *pix)
{
	t_cam	*save;
	t_image	*new;

	save = s.cam;
	d->list = NULL;
	while (s.cam != NULL)
	{
		if (!(new = (t_image *)malloc(sizeof(t_image))))
			return (0);
		new->next = NULL;
		new->img = mlx_new_image(d->init, s.res_x, s.res_y);
		new->data = mlx_get_data_addr(new->img, &new->bits, \
		&new->size, &new->end);
		checkpixel(s, new->data, pix);
		ft_add_img(&(d->list), new);
		s.cam = s.cam->next;
	}
	d->save_img = d->list;
	s.cam = save;
	return (1);
}
