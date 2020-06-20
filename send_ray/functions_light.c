/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:58:37 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/16 15:25:53 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

void	final_light(t_lum *light, t_close *inter, double i)
{
	if (!light->color.x && inter->col_form.x)
		light->color.x = 1;
	if (!light->color.y && inter->col_form.y)
		light->color.y = 1;
	if (!light->color.z && inter->col_form.z)
		light->color.z = 1;
	if (light->color.x && !inter->col_form.x)
		inter->col_form.x = 1;
	if (light->color.y && !inter->col_form.y)
		inter->col_form.y = 1;
	if (light->color.z && !inter->col_form.z)
		inter->col_form.z = 1;
	inter->col_final.x += light->ratio * i * 10 * light->color.x * inter->col_form.x;
	inter->col_final.y += light->ratio * i * 10 * light->color.y * inter->col_form.y;
	inter->col_final.z += light->ratio * i * 10 * light->color.z * inter->col_form.z;
	if (inter->col_final.x > 255)
		inter->col_final.x = 255;
	if (inter->col_final.y > 255)
		inter->col_final.y = 255;
	if (inter->col_final.z > 255)
		inter->col_final.z = 255;
}

void	amb_light(t_scene s, t_close *inter)
{
	inter->col_final.x = s.color_lum_amb.x * inter->col_form.x * s.lum_amb;
	inter->col_final.x /= 10;
	inter->col_final.y = s.color_lum_amb.y * inter->col_form.y * s.lum_amb;
	inter->col_final.y /= 10;
	inter->col_final.z = s.color_lum_amb.z * inter->col_form.z * s.lum_amb;
	inter->col_final.z /= 10;
}