/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:39:26 by vileleu           #+#    #+#             */
/*   Updated: 2020/07/21 16:52:04 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/send_ray.h"

int		mod(int w, int type)
{
	int	mod;

	mod = w % 4;
	if (mod != 0)
		return (4 - mod);
	else
		return (type);
}

void	create_header(int fd, int w, int h)
{
	unsigned char	header[54];
	unsigned int	*put_int;
	int				i;

	i = 0;
	while (i < 54)
		header[i++] = 0;
	header[0] = 66;
	header[1] = 77;
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 24;
	put_int = (unsigned int *)&header[2];
	*put_int = h * mod(w, 1) + w * h * 3 + 54;
	put_int = (unsigned int *)&header[18];
	*put_int = w;
	put_int = (unsigned int *)&header[22];
	*put_int = h;
	put_int = (unsigned int *)&header[34];
	*put_int = h * mod(w, 1) + w * h * 3;
	write(fd, header, 54);
}

void	write_data(int fd, t_scene s, int *nb, char *data)
{
	int		i;
	int		j;

	j = s.res_x * s.res_y * 4 - s.res_x * 4 - *nb;
	i = j + s.res_x * 4;
	while (j < i)
	{
		write(fd, &data[j++], sizeof(char));
		write(fd, &data[j++], sizeof(char));
		write(fd, &data[j++], sizeof(char));
		j++;
	}
	i = 0;
	while (i++ < mod(s.res_x, 0))
		write(fd, 0, 1);
	*nb = *nb + s.res_x * 4;
}

int		save_bmp(t_scene s, char *name, char *data)
{
	int		i;
	int		nb;
	int		fd;

	i = 0;
	nb = 0;
	if (!(fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR)))
		return (0);
	create_header(fd, s.res_x, s.res_y);
	while (i++ < s.res_y)
		write_data(fd, s, &nb, data);
	close(fd);
	return (1);
}
