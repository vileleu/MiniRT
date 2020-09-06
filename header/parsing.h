/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:19:37 by vileleu           #+#    #+#             */
/*   Updated: 2020/09/04 17:40:42 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct	s_color
{
	double	x;
	double	y;
	double	z;
}				t_color;

typedef struct	s_cam
{
	t_vect			crdn;
	t_vect			orientation;
	int				fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_lum
{
	t_vect			crdn;
	double			ratio;
	t_color			color;
	struct s_lum	*next;
}				t_lum;

typedef struct	s_sp
{
	t_vect		crdn;
	double		diameter;
	t_color		color;
	struct s_sp	*next;
}				t_sp;

typedef struct	s_pl
{
	t_vect		crdn;
	t_vect		orientation;
	t_color		color;
	struct s_pl	*next;
}				t_pl;

typedef struct	s_sq
{
	t_vect		crdn;
	t_vect		orientation;
	double		height;
	t_color		color;
	t_vect		a;
	t_vect		b;
	t_vect		c;
	t_vect		d;
	struct s_sq	*next;
}				t_sq;

typedef struct	s_cy
{
	t_vect		crdn;
	t_vect		orientation;
	double		diameter;
	double		height;
	t_color		color;
	struct s_cy	*next;
}				t_cy;

typedef struct	s_tr
{
	t_vect		crdn1;
	t_vect		crdn2;
	t_vect		crdn3;
	t_color		color;
	struct s_tr	*next;
}				t_tr;

typedef struct	s_rot
{
	t_vect	x_rot;
	t_vect	y_rot;
	t_vect	z_rot;
}				t_rot;

typedef struct	s_scene
{
	int		res_x;
	int		res_y;
	int		verifr;
	double	lum_amb;
	t_color	color_lum_amb;
	int		verifa;
	t_cam	*cam;
	t_lum	*lum;
	t_sp	*sp;
	t_pl	*pl;
	t_sq	*sq;
	t_cy	*cy;
	t_tr	*tr;
	t_rot	rot;
}				t_scene;

double			ft_atof(char *str, int *ptr);
double			ft_atof3p(char *str, int *ptr, t_vect *point);
int				ft_atoi(char *str, int *ptr);
int				ft_atoi3(char *str, int *ptr, t_color *color);
t_vect			ope(char c, t_vect a, t_vect b);

int				bef_pars(t_scene *s, char **av);
void			init_scene(t_scene *s);
void			initialize_vect(t_vect *a);
t_vect			create_point(double a, double b, double c);

int				whitespace(char *str, int *ptr);
int				get_next_line(int fd, char **line);

int				resolution(char *str, t_scene *s, int i);
int				ambiante(char *str, t_scene *s, int i);
int				camera(char *str, t_scene *s, int i);
int				lumiere(char *str, t_scene *s, int i);

int				sphere(char *str, t_scene *s, int i);
int				plane(char *str, t_scene *s, int i);
int				square(char *str, t_scene *s, int i);
int				cylindre(char *str, t_scene *s, int i);
int				triangle(char *str, t_scene *s, int i);
void			square2(t_sq *o);
int				cylindre2(char *str, int *ptr, t_cy *o);
int				triangle2(char *str, int *ptr, t_tr *o);

void			ft_add_sp(t_sp **alst, t_sp *new);
void			ft_add_pl(t_pl **alst, t_pl *new);
void			ft_add_sq(t_sq **alst, t_sq *new);
void			ft_add_cy(t_cy **alst, t_cy *new);
void			ft_add_tr(t_tr **alst, t_tr *new);

void			ft_add_cam(t_cam **alst, t_cam *new);
void			ft_add_lum(t_lum **alst, t_lum *new);

t_rot			rot_apply(t_vect ori);
void			matrix_app(t_rot r, t_vect *ray);

int				error(int verif, t_scene *s);

#endif
