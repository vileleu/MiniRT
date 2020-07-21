/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:03:50 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 18:41:35 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		fatal(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (0);
}

int		create_bmp(t_scene s)
{
	char	*data;
	t_pixel	pix;

	if (!(data = malloc(sizeof(char) * s.res_x * s.res_y * 4 + 1)))
		return (0);
	checkpixel(s, data, &pix);
	if (!(save_bmp(s, "save.bmp", data)))
		return (0);
	free(data);
	return (1);
}

int		main(int ac, char **av)
{
	t_scene	s;

	if (ac < 2)
		return (fatal("need file .rt in arguments\n"));
	else if (ac > 4)
		return (fatal("too many arguments\n"));
	init_scene(&s);
	if (!(bef_pars(&s, av)))
		return (0);
	if (ac == 3 && (ft_strcmp(av[2], "-save")) == 0)
	{
		if (s.cam->next)
		{
			error(10, &s);
			return (fatal("too many camera for argument '-save'\n"));
		}
		if (!(create_bmp(s)))
		{
			error(10, &s);
			return (fatal("error during creation of bmp file\n"));
		}
	}
	else
		mlx_cam(s);
	return (0);
}
