/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:19:26 by vileleu           #+#    #+#             */
/*   Updated: 2020/02/05 18:10:37 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

void	ft_add_cam(t_cam **alst, t_cam *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_add_lum(t_lum **alst, t_lum *new)
{
	new->next = *alst;
	*alst = new;
}
