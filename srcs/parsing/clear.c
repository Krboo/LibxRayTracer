/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:58:32 by qduperon          #+#    #+#             */
/*   Updated: 2016/10/24 17:37:44 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		ft_clear_obj(t_obj **start)
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
