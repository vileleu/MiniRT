/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:56:16 by vileleu           #+#    #+#             */
/*   Updated: 2020/06/20 18:29:30 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_RAY_H
# define SEND_RAY_H
# define PI 3.141592
# define ABS(Value) (Value < 0 ? -Value : Value)
# define E 0.001
# define SPHERE 1
# define PLAN 2
# define CARRE 3
# define CYLINDRE 4
# define TRIANGLE 5

# include <math.h>
# include "../header/parsing.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct	s_pixel
{
	int	i;
	int	j;
	int	col;
}				t_pixel;

typedef struct	s_ray
{
	t_vect	origin;
	t_vect	direction;
}				t_ray;

typedef struct	s_close
{
	int		form;
	double	solu;
	double	dist;
	t_vect	cam;
	t_vect	coord;
	t_color	col_form;
	t_vect	inter;
	t_vect	normale;
	t_color	col_final;
}				t_close;

typedef struct	s_libx
{
	int		prems;
	void	*init;
	void	*win;
	void	*img;
	char	*data;
	int		bits;
	int		size;
	int		end;
	t_scene	sah;
	t_cam	*save_cam;
}				t_libx;

/*
**	Manipulation de vecteur
*/

t_vect			ope(char c, t_vect a, t_vect b);
double			prodscal(t_vect a, t_vect b);
t_vect			multi(t_vect a, double b);
t_vect			normalize(t_vect v);
double			norme2(t_vect a);
int				samevect(t_vect a, t_vect b);
void			initialize_vect(t_vect *a);
void			initialize_color(t_color *a);

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
t_close			enlight_obj(t_scene s, t_close *inter, t_ray ray_light);

/*
**	Spheres
*/

void			inter_sp(t_scene s, t_close *inter, t_ray ray);
void			iter_sp(t_scene s, t_close *inter, t_ray ray, t_vect verif);

void			inter_pl(t_scene s, t_close *inter, t_ray ray);
void			iter_pl(t_scene s, t_close *inter, t_ray ray, t_vect verif);

/*
**	MLX
*/

int				mlx_cam(t_scene s);
int				deal_key(int key, void *param);

void			checkpixel(t_scene s, t_libx *d, t_pixel *pix);

/*
**	Autres
*/

double			return_smallest(double x1, double x2);
void			initialize_inter(t_close *inter);

int				shadowsp(t_ray ray, t_close *inter, t_sp *sp, t_lum *light);

#endif
