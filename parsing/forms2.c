/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:04:31 by vileleu           #+#    #+#             */
/*   Updated: 2020/02/05 18:10:44 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

int		cylindre2(char *str, int *ptr, t_cy *o)
{
	if (!(whitespace(str, ptr)))
		return (0);
	if (!(ft_atoi3(str, ptr, &(o->color))))
		return (0);
	if (!(whitespace(str, ptr)))
		return (0);
	return (1);
}

int		triangle2(char *str, int *ptr, t_tr *o)
{
	if (!(whitespace(str, ptr)))
		return (0);
	if (!(ft_atoi3(str, ptr, &(o->color))))
		return (0);
	if (!(whitespace(str, ptr)))
		return (0);
	return (1);
}