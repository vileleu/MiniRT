/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:03:50 by vileleu           #+#    #+#             */
/*   Updated: 2020/03/05 13:30:09 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		main(int ac, char **av)
{
	t_scene	s;

	if (ac < 2 && ac > 3)
		return (0);
	init_scene(&s);
	if (!(bef_pars(&s, av)))
		return (0);
	mlx_cam(s);
	return (0);
}