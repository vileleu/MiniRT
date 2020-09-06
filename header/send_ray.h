/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:56:16 by vileleu           #+#    #+#             */
/*   Updated: 2020/09/06 16:03:15 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_RAY_H
# define SEND_RAY_H
# define PI 3.141592
# define E 0.001

# include <math.h>
# include "../header/parsing.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct	s_pixel
{
	int		i;
	int		j;
	int		col;
}				t_pixel;

typedef struct	s_ray
{
	t_vect	origin;
	t_vect	direction;
}				t_ray;

typedef struct	s_close
{
	double	solu;
	double	dist;
	t_color	col_form;
	t_vect	inter;
	t_vect	normale;
	t_color	col_final;
}				t_close;

typedef struct	s_image
{
	char			*data;
	void			*img;
	int				bits;
	int				size;
	int				end;
	struct s_image	*next;
}				t_image;

typedef struct	s_libx
{
	void	*init;
	void	*win;
	t_image	*list;
	t_scene	sah;
	t_image	*save_img;
}				t_libx;

typedef	struct	s_bmp
{
	int		sign[2];
	int		size;
	int		reserved;
	int		offset;
	int		info;
	int		w;
	int		h;
	int		plan;
	int		bbp;
	int		comp;
	int		sizedata;
	int		resw;
	int		resh;
	int		nbcolor;
	int		nbimport;
}				t_bmp;

/*
**	Manipulation de vecteur
*/

double			prodscal(t_vect a, t_vect b);
t_vect			multi(t_vect a, double b);
t_vect			divi(t_vect a, double b);
t_vect			normalize(t_vect v);
double			norme2(t_vect a);
void			initialize_color(t_color *a);
void			add_color(t_color *a, t_color b);
void			add_point(t_vect *a, t_vect b);
t_vect			croisement(t_vect a, t_vect b);

/*
**	Rayons
*/

t_ray			newray(t_scene s, t_pixel pix);
t_ray			newray_enlight(t_close *inter, t_lum *light);

/*
**	Lumieres
*/

void			final_light(t_lum *light, t_close *inter, double i);
void			amb_light(t_scene s, t_close *inter);
int				enlight(t_scene s, t_close *inter, t_lum *light);

/*
**	Formes
*/

void			inter_sp(t_scene s, t_close *inter, t_ray ray);
void			inter_pl(t_scene s, t_close *inter, t_ray ray);
void			inter_tr(t_scene s, t_close *inter, t_ray ray);
void			inter_sq(t_scene s, t_close *inter, t_ray ray);
void			inter_cy(t_scene s, t_close *inter, t_ray ray);

/*
**	MLX
*/

int				mlx_cam(t_scene s);
int				deal_key(int key, void *param);
int				mouse(void *param);
void			checkpixel(t_scene s, char *data, t_pixel *pix);
int				create_image(t_scene s, t_libx *d, t_pixel *pix);
void			free_image(t_libx *d);

/*
** Rotation
*/

t_rot			rot_verif(t_vect rot, int angle);
int				whichone(t_vect ori);
t_rot			double_x(t_vect ori);
t_rot			matrixprod(t_rot r, t_rot re);

/*
**	Autres
*/

double			return_smallest(double x1, double x2);
void			initialize_inter(t_close *inter);
int				save_bmp(t_scene s, char *name, char *img);

#endif
