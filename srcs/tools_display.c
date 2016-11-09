/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:18:45 by qduperon          #+#    #+#             */
/*   Updated: 2016/11/09 09:13:01 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		putdisplay(t_env *env)
{
	ft_putendl("-----current scene-----");
	putcam(env);
	putlight(env);
	putobj(env);
	ft_putendl("-----------------------");
}
