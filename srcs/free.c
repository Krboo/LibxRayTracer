/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:32:01 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/04 16:42:30 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		free_obj(t_obj **start)
{
	t_obj	*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}

void		free_spots(t_spot **start)
{
	t_spot		*tmp;

	while (*start != NULL)
	{
		tmp = (*start)->next;
		(*start)->next = NULL;
		free(*start);
		*start = tmp;
	}
}

void		free_all(t_env *env)
{
	free(env->img);
	free_obj(&env->obj);
	free_spots(&env->spots);
	free(env);
}
