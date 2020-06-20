/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_forms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vileleu <vileleu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:38:42 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/05 18:10:41 by vileleu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"

void	ft_add_sp(t_sp **alst, t_sp *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_add_pl(t_pl **alst, t_pl *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_add_sq(t_sq **alst, t_sq *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_add_cy(t_cy **alst, t_cy *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_add_tr(t_tr **alst, t_tr *new)
{
	new->next = *alst;
	*alst = new;
}
