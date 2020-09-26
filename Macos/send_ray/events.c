/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:03:05 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:26:24 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		deal_key(int key, void *param)
{
	t_libx	*d;

	d = (t_libx*)param;
	if (key == 53)
	{
		free_image(d);
		mlx_destroy_window(d->init, d->win);
		exit(0);
	}
	else if (key == 49)
	{
		if (d->list->next == NULL)
			d->list = d->save_img;
		else
			d->list = d->list->next;
		mlx_put_image_to_window(d->init, d->win, d->list->img, 0, 0);
	}
	return (0);
}

int		mouse(void *param)
{
	deal_key(53, param);
	return (0);
}
