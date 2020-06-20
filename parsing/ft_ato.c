/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:38:18 by vileleu           #+#    #+#             */
/*   Updated: 2020/03/09 17:12:33 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		ft_atoi(char *str, int *ptr)
{
	int nb;
	int	nega;

	nb = 0;
	nega = 1;
	if (str[(*ptr)++] == '-')
		nega = -1;
	else
		(*ptr)--;
	while (str[*ptr] >= 48 && str[*ptr] <= 57)
		nb = nb * 10 + (str[(*ptr)++] - 48);
	return (nb * nega);
}

int		ft_atoi3(char *str, int *ptr, t_color *color)
{
	color->x = ft_atoi(str, ptr);
	if (str[(*ptr)++] != ',')
		return (0);
	color->y = ft_atoi(str, ptr);
	if (str[(*ptr)++] != ',')
		return (0);
	color->z = ft_atoi(str, ptr);
	return (1);
}

double	ft_atof(char *str, int *ptr)
{
	double	nb;
	double	dec;
	int		power;
	int		nega;

	nb = 0;
	dec = 0;
	power = 1;
	nega = 1;
	if (str[(*ptr)++] == '-')
		nega = -1;
	else
		(*ptr)--;
	nb = ft_atoi(str, ptr);
	if (str[*ptr] == '.')
	{
		(*ptr)++;
		while (str[*ptr] >= 48 && str[*ptr] <= 57 && power++)
			dec = dec * 10 + (str[(*ptr)++] - 48);
	}
	nb = nb + dec / pow(10, power - 1);
	return (nb * nega);
}

double	ft_atof3p(char *str, int *ptr, t_vect *point)
{
	point->x = ft_atof(str, ptr);
	if (str[(*ptr)++] != ',')
		return (0);
	point->y = ft_atof(str, ptr);
	if (str[(*ptr)++] != ',')
		return (0);
	point->z = ft_atof(str, ptr);
	return (1);
}
