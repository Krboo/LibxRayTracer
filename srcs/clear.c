/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:58:32 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/15 16:26:19 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ft_clear_cone(t_cone **start)
{
	t_cone	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		ft_deleted_vect((*start)->pos);
		ft_deleted_color((*start)->color);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
void		ft_deleted_cylindre(t_cylind **start)
{
	t_cylind	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		ft_deleted_vect((*start)->pos);
		ft_deleted_color((*start)->color);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}

void		ft_deleted_plan(t_plan **start)
{
	t_plan	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		ft_deleted_vect((*start)->pos);
		ft_deleted_color((*start)->color);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
void		ft_deleted_sphere(t_sphere **start)
{
	t_sphere	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		ft_deleted_vect((*start)->pos);
		ft_deleted_color((*start)->color);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
void		ft_deleted_spot(t_spot **start)
{
	t_spot	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		ft_deleted_vect((*start)->pos);
		ft_deleted_color((*start)->color);
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}
